open ReasonJs;
open VertexStructure;
open Types;

module PipeLine = {
    type pipe = {
        cullMode: Types.cullmode,
        /* ToDo: more here */

        program: GL.programT,
        vertexStructure: VertexStructure.vertexStructure, /* ToDo: This is actually an array of structures */
        vertexShader: string,
        fragmentShader: string,
    };

    let make = fun (gl, vertexStructure, vertexShader, fragmentShader) => {
        let x : pipe = {
            cullMode: None,
            program: GL.(createProgram gl),
            vertexStructure,
            vertexShader,
            fragmentShader
        };

        x
    };


    let compileShader = fun (gl, shaderType, source) => {
        let s = GL.(createShader gl shaderType);
        GL.(shaderSource gl s source);
        GL.(compileShader gl s);

        log(GL.(getShaderInfoLog gl s));

        /*
        if (!SystemImpl.gl.getShaderParameter(s, GL.COMPILE_STATUS)) {
            throw "Could not compile shader:\n" + SystemImpl.gl.getShaderInfoLog(s);
        }
        */

        s
    };

    let compile = fun (gl: GL.glT, p: pipe) => {
        let vertexShader = compileShader(gl, GL._VERTEX_SHADER, p.vertexShader);
        let fragmentShader = compileShader(gl, GL._FRAGMENT_SHADER, p.fragmentShader);
        let program = p.program;
        GL.(attachShader gl program vertexShader);
        GL.(attachShader gl program fragmentShader);

/*
        for (structure in inputLayout) {
            for (element in structure.elements) {
                SystemImpl.gl.bindAttribLocation(program, index, element.name);
                if (element.data == VertexData.Float4x4) {
                    index += 4;
                }
                else {
                    ++index;
                }
            }
        }
*/
        /* this doesn't work with Float4x4 */
        /* ToDo I can't get this compiling: !!! List.mapi (fun (i : int, e : VertexStructure.element) => { GL.(bindAttribLocation gl program i e.name) }) p.vertexStructure; */
        GL.(bindAttribLocation gl program 0 "pos");


        GL.(linkProgram gl program);


        log(GL.(getProgramInfoLog gl program));

        /*
        if (!SystemImpl.gl.getProgramParameter(program, GL.LINK_STATUS)) {
            throw "Could not link the shader program:\n" + SystemImpl.gl.getProgramInfoLog(program);
        }
        */
    };

    let set = fun (gl, p) => {
        GL.(useProgram gl p.program);
/*
        for (index in 0...textureValues.length) SystemImpl.gl.uniform1i(textureValues[index], index);
        SystemImpl.gl.colorMask(colorWriteMaskRed, colorWriteMaskGreen, colorWriteMaskBlue, colorWriteMaskAlpha);
*/
    }
};
