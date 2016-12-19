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
  let make = fun(gl: GL.glT, vertexCount: int, structure: VertexStructure.vertexStructure, newUsage: usage, instanceDataStepRate: int , canRead: bool) => {
    let stride = 0;
    /* let stride = List.fold_left (fun(x) => {
              fun (y) => {
                x 
              }}) 0 sizes;
    */

    let stride = List.fold_left (fun acc x => { (acc +  4 * 3) /* todo not just Float3 */ }) 0 structure;


    let foo = ((vertexCount * stride) / 4);
    let data = Array.make foo 0.0;

    let vbuffer:vertexBuffer = {
      buffer:GL.(createBuffer gl),
      usage:newUsage,
      instanceDataStepRate:instanceDataStepRate,
      mySize:vertexCount,
      myStride:stride,
      sizes: Array.make vertexCount 0,
      offsets: Array.make vertexCount 0,
      data
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
    GL.(deleteBuffer gl vbuffer.buffer);
  }

};
