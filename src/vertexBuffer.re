open ReasonJs;
open Array;
open Usage;
open VertexStructure;
open VertexData;

type float32Array = array float;
module VertexBuffer = {
  type vertexBuffer = {
    buffer:GL.webGLBuffer,
    data: float32Array,
    mutable mySize: int,
    mutable myStride: int,
    sizes: array int,
    offsets: array int,
    mutable usage: usage,
    mutable instanceDataStepRate: int
  };
  /* canRead standardmaessig true
    instanceDataStepRate = 0
  */
  let news = fun(vbuffer:vertexBuffer, vertexCount: int, structure: VertexStructure.vertexStructure, newUsage: usage, instanceDataStepRate: int , canRead: bool ) => {
    vbuffer.usage = newUsage;
    vbuffer.instanceDataStepRate = instanceDataStepRate;
    vbuffer.mySize = vertexCount;
    vbuffer.myStride = 0;
    Array.iter(fun el => {
      let size = switch el.vertexData {
      | VertexData.Float1 => 4*1
      | VertexData.Float2 => 4*2
      | VertexData.Float3 => 4*3;
      };
    } structure.elements);
  }
};

/* public function new(vertexCount: Int, structure: VertexStructure, usage: Usage, instanceDataStepRate: Int = 0, canRead: Bool = false);
public function delete(): Void;
public function lock(?start: Int, ?count: Int): Float32Array;
public function unlock(): Void;
public function count(): Int;
public function stride(): Int; */
