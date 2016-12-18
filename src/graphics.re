open ReasonJs;

type cullmode =
    | Clockwise
    | CounterClockwise
    | None;

module VertexStructure = {
    type vertexdata =
        | Float1
        | Float2
        | Float3
        | Float4;
        /* ToDo: | Float4x4; */

    type element = {
        name: string,
        vertexData: vertexdata
    };

    let makeOne = fun (name, vertexData) => {
        let x : element = {
            name,
            vertexData
        };

        [x]
    };

    type structure = list element;
};

module PipeLine = {
    type pipe = {
        cullMode: cullmode,
        /* ToDo: more here */

        program: GL.programT,
        vertexStructure: VertexStructure.structure, /* ToDo: This is actually an array of structures */
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

        /* XXX structure */

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

module Graphics = {
    type color = {r: float, g: float, b: float, a: float};

    /* Begin is overloaded */
    let begin_ = fun (gl) => {

        GL.(enable gl GL._BLEND);
        GL.(blendFunc gl GL._SRC_ALPHA GL._ONE_MINUS_SRC_ALPHA);

/*
        if (renderTarget == null) {
            SystemImpl.gl.bindFramebuffer(GL.FRAMEBUFFER, null);
            SystemImpl.gl.viewport(0, 0, System.windowWidth(), System.windowHeight());
        } else {
            ..
        }
*/

    };


    let clear = fun (gl, c : color) => {
        GL.(clearColor gl c.r c.g c.b c.a);
        GL.(clear gl GL._COLOR_BUFFER_BIT);
    };

    let setCullMode = fun (gl, cullMode : cullmode) => {
        switch cullMode {
            | None => GL.(disable gl GL._CULL_FACE);
            | Clockwise => {
                GL.(enable gl GL._CULL_FACE);
                GL.(cullFace gl GL._BACK);
            }
            | CounterClockwise => {
                GL.(enable gl GL._CULL_FACE);
                GL.(cullFace gl GL._FRONT);
            }
        }
    };


    let setPipeline = fun (gl, pipe : PipeLine.pipe) => {
        setCullMode(gl, pipe.cullMode);
        /*
        setDepthMode(pipe.depthWrite, pipe.depthMode);
        setStencilParameters(pipe.stencilMode, pipe.stencilBothPass, pipe.stencilDepthFail, pipe.stencilFail, pipe.stencilReferenceValue, pipe.stencilReadMask, pipe.stencilWriteMask);
        setBlendingMode(pipe.blendSource, pipe.blendDestination, pipe.blendOperation, pipe.alphaBlendSource, pipe.alphaBlendDestination, pipe.alphaBlendOperation);
        pipe.set();
        */
        PipeLine.set(gl, pipe);
    };

};