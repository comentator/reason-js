open ReasonJs;
open Array;
open Usage;
open VertexStructure;
open VertexElement;
open VertexData;


module VertexBuffer = {

  type vertexBuffer = {
    buffer: GL.bufferT,
    mutable data: Float32Array.float32Array,
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
    let getCurrentOffset = fun(idx) => {
      if(idx==0){
        0;
      }else{
        Array.get offsets idx-1;
      };
    };
    List.iteri(
      fun index el => {
        let y : VertexElement.vertexElement = el;
        let size = switch y.vertexData {
          | Float1 => 1
          | Float2 => 2
          | Float3 => 3
          | Float4 => 4
        };
        let currentOffset = getCurrentOffset(index);
        Array.set sizes index size;
        Array.set offsets index currentOffset;
      }) structure;
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

  let lock = fun (vbuffer:vertexBuffer) => {
    vbuffer.data;
  };

  let unlock = fun (gl: GL.glT, vbuffer:vertexBuffer) => {
    GL.(bindBuffer gl GL._ARRAY_BUFFER vbuffer.buffer);
    let u = switch vbuffer.usage {
        | StaticUsage => GL._STATIC_DRAW
        | DynamicUsage => GL._DYNAMIC_DRAW
        | ReadableUsage => GL._STATIC_DRAW
    };

    GL.(bufferData gl GL._ARRAY_BUFFER glData u);
  };



  let delete = fun (gl: GL.glT,vbuffer: vertexBuffer) => {
    vbuffer.data = Array.make 0 0.0;
    GL.(deleteBuffer gl vbuffer.buffer);
  };

  let set = fun (gl: GL.glT, vbuffer: vertexBuffer, offset: int) => {
    GL.(bindBuffer gl GL._ARRAY_BUFFER vbuffer.buffer);

    Array.iteri (fun i size => {
      let attributesOffset = i;
      /* todo size > 4 */
      /* have to change from i something else after implementing that */


    GL.(enableVertexAttribArray gl (offset + attributesOffset));
    let thisoffset = Array.get vbuffer.offsets i;
    GL.(vertexAttribPointer gl (offset + attributesOffset) size GL._FLOAT false vbuffer.myStride thisoffset);

    }) vbuffer.sizes;
  };

};
