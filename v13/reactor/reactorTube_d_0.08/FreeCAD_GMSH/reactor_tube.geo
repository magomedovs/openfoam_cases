SetFactory("OpenCASCADE");
Merge "reactor_tube.step";
//+
Physical Surface("outlet", 12) = {8};
//+
Physical Surface("tube_inner_surface", 13) = {7};
//+
Physical Surface("tube_bottom_ring", 14) = {6};
//+
Physical Surface("tube_outer_surface", 15) = {5};
//+
Physical Surface("reactor_top", 16) = {4};
//+
Physical Surface("reactor_side_surface", 17) = {3};
//+
Physical Surface("reactor_inlet_nozzle", 18) = {2};
//+
Physical Surface("inlet", 19) = {1};
//+
Physical Volume("reactor_and_tube_volume", 20) = {1};

// Set global mesh size (override with finer control as needed)
Mesh.CharacteristicLengthMin = 0.005;  // minimum grid size
Mesh.CharacteristicLengthMax = 0.5;  // maximum grid size

// Optional: Set finer mesh size on specific volume, surface, or curve by IDs
// Characteristic Length {Volume{1};} = 0.5;

// Generate 3D mesh
Mesh 3;