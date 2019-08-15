!!ver 330
//author: Antonio "toneddu2000" Latronico
//placed under cc0 public domain license
#ifdef VERTEX_SHADER
attribute vec2 v_texcoord;
varying vec2 v_edge;
void main(void)
{
  gl_Position = ftetransform();
  v_edge = v_texcoord.xy;
}
#endif

#ifdef FRAGMENT_SHADER
void main() {
	float al=0.35;
	
	#ifdef GREENLIGHT
		gl_FragColor.rgb = vec3(0.248,0.840,0.293);
		al = 0.2;
	#endif
	#ifdef GREENDARK
		gl_FragColor.rgb = vec3(0.115,0.390,0.136);
	#endif
	#ifdef AZURE
		gl_FragColor.rgb = vec3(0.666,0.823,0.912);
	#endif
	#ifdef RED
		gl_FragColor.rgb = vec3(0.910,0.081,0.116);
		al = 0.2;
	#endif
	#ifdef GREEN
		gl_FragColor.rgb = vec3(0,0.9,0.1);
		al = 0.2;
	#endif
	#ifdef BLUE
		gl_FragColor.rgb = vec3(0,0.1,0.9);
		al = 0.2;
	#endif
	#ifdef BLUEGROUP
		gl_FragColor.rgb = vec3(0,0.1,0.9);
		al = 0.5;
	#endif
	#ifdef YELLOW
		gl_FragColor.rgb = vec3(0.5,0.5,0);
		al = 0.2;
	#endif
	#ifdef VIOLET
		gl_FragColor.rgb = vec3(1.0,0,1.0);
	#endif
	#ifdef ORANGE
		gl_FragColor.rgb = vec3(1.0,0.4,0);
	#endif
	#ifdef BROWN
		gl_FragColor.rgb = vec3(0.630,0.277,0.035);
	#endif
	#ifdef PINK
		gl_FragColor.rgb = vec3(0.912,0.525,0.747);
	#endif
	#ifdef WHITE
		gl_FragColor.rgb = vec3(1,1,1);
	#endif
	#ifdef REDOPAQUE
		gl_FragColor.rgb = vec3(0.910,0.081,0.116);
		al = 1.0;
	#endif
	#ifdef PURPLE
		gl_FragColor.rgb = vec3(0.401,0.302,0.745);
	#endif
	#ifdef GREY
		gl_FragColor.rgb = vec3(0.445,0.445,0.445);
	#endif
	#ifdef GREYDARK
		gl_FragColor.rgb = vec3(0.330,0.340,0.340);
	#endif
	#ifdef GREYBRIGHT
		gl_FragColor.rgb = vec3(0.695,0.695,0.695);
	#endif
	#ifdef PUREBLACK
		gl_FragColor.rgb = vec3(0,0,0);
		al = 1.0;
	#endif
	//entity custom defines
	#ifdef GRIDLINES
		gl_FragColor.rgb = vec3(0.15,0.15,0.15);
	#endif
	gl_FragColor.a = al;
	if(al<=0.0){
		discard;
	}
}
#endif