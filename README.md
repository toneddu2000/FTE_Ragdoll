# FTE_Ragdoll
Simple ragdoll example with FTEQW game engine. This simple project provides an intuitive way to test ragdolls in FTEQW.
Controls:
Right mouse to toggle cursor placement on/off. Left click to spawn ragdoll at gizmo location.
Space key to swap between scenes and OK to launch chosen scene.
Tab to display bone names.
A key to toggle animation-driven ragdolls (ragdoll animation will start at the end of animation).
Known bugs:
1)Dismemberment seems not to work. It doesn't allow to choose a different bone in the hierarchy
2)Scene collider MUST be set to SOLID_BSP which doesn't work well with traceline MOVE_HITMODEL so scene has been split in planes and colliders.
3)After 10 ragdolls system performance are too low
4)Animation driven ragdolls doesn't copy last frame position/rotation, giving unrealistic animations
5)ODE seems to work only on Windows