open Graphics;
open ReasonJs;
open VertexStructure;
open VertexData;
open PipeLine;
open IndexBuffer;
open Array;

let canvas = Document.(getElementById "my-canvas");
let gl = Document.(getContext canvas "webgl");

let vertexStructure = VertexStructure.makeOne("pos", Float3);

let vertexShader = "attribute vec3 pos;" ^
"void main() { " ^
"    gl_Position = vec4(pos.x, pos.y, 0.5, 1.0); " ^
"}";

let fragmentShader = "void main() {" ^
"    gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);" ^
"}";

let pipe = PipeLine.make(gl, vertexStructure, vertexShader, fragmentShader);
PipeLine.compile(gl, pipe);

let indices = IndexBuffer.make(gl, 3, Usage.StaticUsage);
let i = IndexBuffer.lock indices;
Array.set i 0 0;
Array.set i 1 1;
Array.set i 2 2;
IndexBuffer.unlock(gl, indices);

let rec render = fun () => {
    Window.(requestAnimationFrame window render);

    Graphics.begin_(gl);
    let c : Graphics.color = {r: 0.5, g: 0.3, b: 1.0, a: 1.0};
    Graphics.clear(gl, c);
    Graphics.setPipeline(gl, pipe);
    Graphics.setIndexBuffer(gl, indices);
    Graphics.drawIndexedVertices(gl, 0, 3);
};

Window.(requestAnimationFrame window render);
