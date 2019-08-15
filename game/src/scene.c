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

void Scene_Precaches()
{
	precache_model("models/ragtest2.iqm");
	precache_model("models/collision_plane.iqm");
	precache_model("models/collision_slide.iqm");
	precache_model("models/collision_obstacle.iqm");
	precache_model("models/collision_curved.iqm");
	precache_model("models/collision_ballmoving.iqm");
	precache_model("models/gizmo.iqm");
}

void Scene_Init()
{
	//store scene_num cvar
	sceneNum = cvar("scene_num");
	scenePureBSP = cvar("scene_purebsp");
	Scene_Precaches();
	
	//create gizmo
	sceneGizmo = spawn();
	setorigin(sceneGizmo,[0,0,180]);
	setmodel(sceneGizmo,"models/gizmo.iqm");
	sceneGizmo.solid = SOLID_NOT;
	setsize(sceneGizmo,sceneGizmo.mins,sceneGizmo.maxs);
	
	//create scene sceneCollision model
	//NOTE: SOLID_BSP is mandatory to make scene collide with ragdolls
	//to avoid ragdolls with .ragdollActive = FALSE not touching ground
	//we need to split scene - colliders(curve,obstacle,slide,etc) and planes, both with SOLID_BSP set
	sceneCollision = spawn();
	setorigin(sceneCollision,[0,0,32]);
	sceneCollision.gameClass = GAME_CLASS_SCENECOLLISION;
	switch(sceneNum){
		case 0:
			setmodel(sceneCollision,"models/collision_slide.iqm");
		break;
		case 1:
			setmodel(sceneCollision,"models/collision_obstacle.iqm");
		break;
		case 2:
			setmodel(sceneCollision,"models/collision_curved.iqm");
		break;
		case 3:
			setorigin(sceneCollision,[0,0,64]);
			setmodel(sceneCollision,"models/collision_ballmoving.iqm");
		break;
		default:
			
		break;
	}
	if(scenePureBSP){
		sceneCollision.solid = SOLID_SLIDEBOX;
	}
	else{
		sceneCollision.solid = SOLID_BSP;
	}
	setsize(sceneCollision,sceneCollision.mins,sceneCollision.maxs);
	sceneCollision.forceshader = shaderforname ("checker2");
	//plane
	scenePlane = spawn();
	setorigin(scenePlane,[0,0,32]);
	setmodel(scenePlane,"models/collision_plane.iqm");
	scenePlane.gameClass = GAME_CLASS_SCENECOLLISION;
	if(scenePureBSP){
		scenePlane.solid = SOLID_SLIDEBOX;
	}
	else{
		scenePlane.solid = SOLID_BSP;
	}
	setsize(scenePlane,scenePlane.mins,scenePlane.maxs);
	scenePlane.forceshader = shaderforname ("checker2");
}

void Scene_Update()
{
	if(sceneCollision){
		if(cvar("scene_num") == 3){
			if(sceneCollision){
				setorigin(sceneCollision,
				[sceneCollision.origin_x,sin(time*32)*3,64]);
				setsize(sceneCollision,sceneCollision.mins,sceneCollision.maxs);
			}
		}
		if(!scenePureBSP){
			addentity(sceneCollision);
		}
	}
	if(scenePlane){
		if(!scenePureBSP){
			addentity(scenePlane);
		}
	}
	if(sceneGizmo){
		addentity(sceneGizmo);
	}
}