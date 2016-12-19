open Graphics;
open ReasonJs;
open VertexStructure;
open VertexData;
open PipeLine;
open VertexBuffer;
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

let vertices = VertexBuffer.make(gl, 3, vertexStructure, Usage.StaticUsage, 0, true);
let v = VertexBuffer.lock vertices;
Array.set v 0 (-1.0);
Array.set v 1 (-1.0);
Array.set v 2 0.5;

Array.set v 3  1.0;
Array.set v 4 (-1.0);
Array.set v 5 0.5;

Array.set v 6 (-1.0);
Array.set v 7  1.0;
Array.set v 8 0.5;
VertexBuffer.unlock(gl, vertices);

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
    Graphics.setVertexBuffer(gl, vertices);
    Graphics.setIndexBuffer(gl, indices);
    Graphics.drawIndexedVertices(gl, 0, 3);
};

Window.(requestAnimationFrame window render);
