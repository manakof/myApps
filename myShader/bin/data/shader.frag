#ifdef GL_ES
precision mediump float;
#endif

uniform float u_time;

void main(){
    gl_FragColor = vec4(1.0,sin((u_time)),1.0,1.0);
}
