open ReasonJs;

module Graphics = {
    type color = {r: float, g: float, b: float, a: float};

    /* Begin is overloaded */
    let begin_ = fun gl => {

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


    let clear = fun (gl, c:color) => {
        GL.(clearColor gl c.r c.g c.b c.a);
        GL.(clear gl GL._COLOR_BUFFER_BIT);
    };

};