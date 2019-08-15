//game
.float 			gameClass;
const float 	GAME_CLASS_NULL = 0;
const float 	GAME_CLASS_DOLL = 1;
const float 	GAME_CLASS_SCENECOLLISION = 2;
const float 	GAME_THINK_REFRESH = 0.02;
//scene
entity 			sceneCollision,scenePlane,sceneGizmo;
float			sceneNum,scenePureBSP;
//input
float			inputCursor,inputCursor3dElevation;
const float		INPUT_CURSOR_3D_ELEVATION_MAX = 400;
vector			inputCursorOrigin,inputCursor3dOrg,inputAngles;
//camera
const vector 	CAMERA_ORIGIN_OFFSET = [-300,0,300];
//ragdoll
entity 			doll,ragdollCurrent;
float			ragdollAnimation;
.float 			ragdollActive,ragdollOnGround,ragdollDieAnimation;
//ui
float			uiBoneNames;
const float		UI_HEADER_HEIGHT = 16;