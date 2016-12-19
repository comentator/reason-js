open ReasonJs;
open Array;
open Usage;
open VertexStructure;
open VertexElement;
open VertexData;

type float32Array = array float;
module VertexBuffer = {

  type vertexBuffer = {
    buffer: GL.bufferT,
    mutable data: float32Array,
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
  let make = fun(gl: GL.glT, vertexCount: int, structure: VertexStructure.vertexStructure, newUsage: usage, instanceDataStepRate: int , canRead: bool) => {
    let stride = 0;
    let sizes = Array.make vertexCount 0;
    let offsets = Array.make vertexCount 0;
    let stride = List.fold_left (
      fun acc x => {
        let y : VertexElement.vertexElement = x;
        switch y.vertexData {
          | Float1 => acc + 4*1
          | Float2 => acc + 4*2
          | Float3 => acc + 4*3
          | Float4 => acc + 4*4
        };
      }) 0 structure;
      let vars = {
        offset:0,
        index:0
      }
    List.iter(
      fun el => {
        let size = switch el.vertexData {
          | Float1 => 1
          | Float2 => 2
          | Float3 => 3
          | Float4 => 4
        };
        Array.set sizes vars.index size;
        Array.set offsets vars.index offset;
        var.offset = switch el.vertexData {
          | Float1 => 1
          | Float2 => 2
          | Float3 => 3
          | Float4 => 4
        };
      } structure
    );
    let foo = ((vertexCount * stride) / 4);
    let data = Array.make foo 0.0;

    let vbuffer:vertexBuffer = {
      buffer:GL.(createBuffer gl),
      usage:newUsage,
      instanceDataStepRate:instanceDataStepRate,
      mySize:vertexCount,
      myStride:stride,
      sizes: sizes,
      offsets: offsets,
      data:data
    };
    vbuffer;
  };

  let lock = fun(vbuffer:vertexBuffer)=>{
    vbuffer.data;
  };

  let unlock = fun (gl: GL.glT, vbuffer:vertexBuffer) => {
    GL.(bindBuffer gl GL._ELEMENT_ARRAY_BUFFER vbuffer.buffer);
    let glData = Uint16Array.(make vbuffer.data);
    let u = switch vbuffer.usage {
        | StaticUsage => GL._STATIC_DRAW
        | DynamicUsage => GL._DYNAMIC_DRAW
        | ReadableUsage => GL._STATIC_DRAW
    };
    GL.(bufferData gl GL._ELEMENT_ARRAY_BUFFER glData u);
  };

  let delete = fun (vbuffer: vertexBuffer) => {
    vbuffer.data = Array.make 0 0.0;
    GL.(deleteBuffer gl vbuffer.buffer);
  }



};
