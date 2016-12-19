open Array;
open ReasonJs;
open Usage;

module IndexBuffer = {

    type indexBuffer = {
        buffer: GL.bufferT,
        data: array int,
        size: int,
        usage: usage,
    };

    let make = fun (gl: GL.glT, indexes: int, usage: Usage.usage /* ToDo canRead */) : indexBuffer => {
        buffer: GL.(createBuffer gl),
        data: Array.make indexes 0,
        size: indexes,
        usage
    };

    let lock = fun (indexBuffer: indexBuffer) => {
        indexBuffer.data
    };

    let unlock = fun (gl: GL.glT, indexBuffer: indexBuffer) => {
        GL.(bindBuffer gl GL._ELEMENT_ARRAY_BUFFER indexBuffer.buffer);
        /* ToDo: var glData: Dynamic = SystemImpl.elementIndexUint == null ? new Uint16Array(data) : new js.html.Uint32Array(data); */
        let glData = Uint16Array.(make indexBuffer.data);
        let u = switch indexBuffer.usage {
            | StaticUsage => GL._STATIC_DRAW
            | DynamicUsage => GL._DYNAMIC_DRAW
            | ReadableUsage => GL._STATIC_DRAW
        };
        GL.(bufferData gl GL._ELEMENT_ARRAY_BUFFER glData u);
    };

    let set = fun (gl: GL.glT, indexBuffer: indexBuffer) => {
        GL.(bindBuffer gl GL._ELEMENT_ARRAY_BUFFER indexBuffer.buffer);
    };

};