"# Ammusement-Park" 
1. Project Overview 

The Virtual Amusement Park Simulation is an interactive 3D environment developed using C++ and OpenGL. The project aims to simulate the atmosphere of a bustling theme park, featuring mechanical rides, dynamic lighting, autonomous agents (NPCs), and environmental effects. Users can explore the park, toggle between day and night modes, and experience a multisensory environment with synchronized audio. 

2. Key Features 

Mechanical Rides & Animations 

The park will feature 3–4 distinct rides with realistic motion patterns: 

Ferris Wheel: Continuous rotation around a central axis with gondolas that remain upright using local transformations. 

Roller Coaster: A cart following a predefined spline path with varying speeds based on "gravity." 

Merry-Go-Round: Rotating platform with vertical oscillating movement for the horses. 

Physics-Based Control: Rides will feature realistic start-up (acceleration) and stop (deceleration) sequences. 

Environment & Scenery 

Architectural Elements: A decorative fountain with particle-system water effects, a ticket booth, and an ice cream corner. 

NPC Simulation: Humans (NPCs) will exhibit "Wander" behavior throughout the park. Specific groups will be programmed to form queues at the ticket booth and ice cream shop to simulate a crowd. 

Day/Night Cycle & Lighting 

Day Mode: Bright, directional light representing the sun with ambient environmental lighting. 

Night Mode: The scene transitions to darkness, triggering Point Lights on rides and street lamps. 

Fireworks System: A particle system triggered at night, simulating colorful explosions with gravity and fade-out effects. 

 

Audio Integration 

Positional Audio: Ambient park sounds (crowd chatter, babies crying). 

Event Triggers: Specific sound effects for rides starting/stopping and synchronized "booms" for the firework displays. 

 
