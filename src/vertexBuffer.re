open ReasonJs;
open Array;
open Usage;
open VertexStructure;
open VertexElement;
open VertexData;

type float32Array = array float;
module VertexBuffer = {

  type vertexBuffer = {
    buffer: GL.webGLBuffer,
    data: float32Array,
    mySize: int,
    myStride: int,
    sizes: array int,
    offsets: array int,
    usage: usage,
    instanceDataStepRate: int
  };

  /* canRead standardmaessig true
    instanceDataStepRate = 0
  */
  /* new()*/
  let make = fun(gl: GL.glT,vertexCount: int, structure: VertexStructure.vertexStructure, newUsage: usage, instanceDataStepRate: int , canRead: bool) => {
    let stride = 0;
    let stride =List.fold_left (fun(x) => {
              fun (y) => {
                x
              }});


    let vbuffer:vertexBuffer = {
      buffer:GL.(createBuffer gl)(),
      usage:newUsage,
      instanceDataStepRate:instanceDataStepRate,
      mySize:vertexCount,
      myStride:stride,
      sizes:Array.make vertexCount 0,
      offsets: Array.make vertexCount 0,
      data:Array.make (vertexCount*stride)/4 0.0
    };
    vbuffer;
  }

  let lock = fun(vbuffer:vertexBuffer)=>{
    vbuffer.data;
  };

  let unlock = fun(vbuffer:vertexBuffer) => {
    
  }


};

/* public function new(vertexCount: Int, structure: VertexStructure, usage: Usage, instanceDataStepRate: Int = 0, canRead: Bool = false);
public function delete(): Void;
public function lock(?start: Int, ?count: Int): Float32Array;
public function unlock(): Void;
public function count(): Int;
public function stride(): Int; */
