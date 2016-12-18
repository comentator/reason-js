open ReasonJs;
open Usage;

module IndexBuffer = {

  type indexBuffer = {
    buffer: GL.bufferT,
    data: list int,
    size: int,
    usage: usage,
  };

  let make = fun (gl: GL.glT, indexes: int, usage: Usage.usage /* canRead */) => {
    let x : indexBuffer = {
        buffer: GL.(createBuffer gl),
        data: [0],
        size: indexes,
        usage
    };

    x
  };

  let set = fun (gl: GL.glT, indexBuffer: indexBuffer) => {
    GL.(bindBuffer gl GL._ELEMENT_ARRAY_BUFFER indexBuffer.buffer);
  };

};