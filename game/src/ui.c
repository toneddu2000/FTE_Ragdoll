/*
MIT License

Copyright (c) 2018 Antonio "toneddu2000" Latronico

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

void UI_PostUpdate(float w,float h)
{
	local float barx;
	switch(sceneNum){
		case 0:
			barx = 10;
		break;
		case 1:
			barx = 80;
		break;
		case 2:
			barx = 160;
		break;
		case 3:
			barx = 240;
		break;
		default:
			barx = 20;
		break;
	}
	drawstring([10,10,0], "Slide", [8,8,0],[1,1,1], 1, 0);
	drawstring([80,10,0], "Obstacle", [8,8,0],[1,1,1], 1, 0);
	drawstring([160,10,0], "Curved", [8,8,0],[1,1,1], 1, 0);
	drawstring([240,10,0], "Moving ball", [8,8,0],[1,1,1], 1, 0);
	drawline(6, [barx,30], [barx+50,30], [1,1,1],1);
	Ragdoll_PrintBoneNames(doll);
	drawfill([0,h-60],[w,60], [0,0,0],1);
	drawstring([10,h-50,0], "Right click to toggle cursor/view move. Left click to spawn ragdoll at gizmo location", [6,6,0],[1,1,1], 1, 0);
	drawstring([10,h-40,0], "Mouse wheel to adjust gizmo Z location", [6,6,0],[1,1,1], 1, 0);
	drawstring([10,h-30,0], "A key to enable ragdoll animation-based, Tab key to toggle bone names display", [6,6,0],[1,1,1], 1, 0);
	drawstring([10,h-20,0], "Space to change scene and Enter to confirm. Q to quit.", [6,6,0],[1,1,1], 1, 0);
	if(ragdollAnimation){
		drawstring([w/2-80,40,0], "Ragdoll animation active", [8,8,0],[1,0,0], 1, 0);
	}
	if(scenePureBSP){
		drawstring([w/2-80,50,0], "Scene Pure BSP active", [8,8,0],[0,1,0], 1, 0);
	}
}

void UI_Init()
{
	uiBoneNames = FALSE;
}