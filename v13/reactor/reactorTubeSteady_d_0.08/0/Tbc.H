
auto Tbc = [=](const scalar x) { // linear interpolation
        
    const std::vector<scalar> x_points = {0.0, 0.02, 0.04, 0.06, 0.08, 0.1, 0.12, 0.14, 0.16, 0.18, 0.2, 0.22, 0.24, 0.26, 0.28, 0.3, 0.32, 0.34, 0.36, 0.38, 0.4, 0.42, 0.44, 0.46, 0.48, 0.5, 0.52, 0.54, 0.56, 0.58, 0.6, 0.62, 0.64, 0.66, 0.68, 0.7, 0.72, 0.74, 0.76, 0.78, 0.8, 0.82, 0.84, 0.86, 0.88, 0.9, 0.92, 0.94, 0.96, 0.98, 1.0};   // z-axis coordinate
    // const std::vector<scalar> y_points = {63, 66, 67, 70, 75, 87, 106, 142, 201, 274, 367, 459, 534, 601, 660, 686, 703, 715, 725, 732, 738, 743, 747, 750, 752, 753, 752, 749, 746, 741, 735, 726, 716, 703, 683, 651, 600, 534, 452, 358, 289, 231, 204, 179, 158, 142, 130, 121, 117, 108, 95};       // Celsius degrees
    const std::vector<scalar> y_points = {336, 339, 340, 343, 348, 360, 379, 415, 474, 547, 640, 732, 807, 874, 933, 959, 976, 988, 998, 1005, 1011, 1016, 1020, 1023, 1025, 1026, 1025, 1022, 1019, 1014, 1008, 999, 989, 976, 956, 924, 873, 807, 725, 631, 562, 504, 477, 452, 431, 415, 403, 394, 390, 381, 368};   // Kelvin degrees

    scalar res = 0.;
    
    auto lower = std::lower_bound(x_points.begin(), x_points.end(), x);
    unsigned int right_index = 0;
    unsigned int left_index = 0;
    if (lower == x_points.begin())
    {
        right_index = 1;
    }
    else if (lower == x_points.end())
    {
        right_index = x_points.size()-1;
    }
    else
    {
        right_index = lower - x_points.begin();
    }
    left_index = right_index - 1;

    scalar y_2 = y_points[right_index];
    scalar y_1 = y_points[left_index];
    scalar x_2 = x_points[right_index];
    scalar x_1 = x_points[left_index];

    res = (y_2 - y_1) / (x_2 - x_1) * (x - x_1) + y_1;
    
    return res;
};


// const scalar T_oven_min = 298. + 63.;//63.; // inlet
// const scalar Tmax = 298. + 750.;//750.;
// const scalar T_oven_max = 298. + 95.;//95.; // outlet

// const scalar z_oven_min = 0.;
// const scalar z_heating_min = 0.47;
// const scalar z_heating_max = 0.52;
// // const scalar z_heating_max = 1.;
// const scalar z_oven_max = 1.;

// // For pipeLength = 0.5
// // const scalar z_oven_min = 0.;
// // const scalar z_heating_min = 0.1;
// // const scalar z_heating_max = 0.4;
// // const scalar z_oven_max = 0.5;

// auto heatingFunc = [=](const scalar z) { // linear interpolation to avoid discontinuous BC
//      if ((z >= z_oven_min) && (z < z_heating_min))
//      {
//         return (z - z_oven_min) / (z_heating_min - z_oven_min) * (Tmax - T_oven_min) + T_oven_min;
//      }
//      else if ((z >= z_heating_min) && (z < z_heating_max))
//      {
//         return Tmax;
//      }
//      else if ((z >= z_heating_max) && (z <= z_oven_max))
//      {
//         return (z - z_heating_max) / (z_oven_max - z_heating_max) * (T_oven_max - Tmax) + Tmax;
//      }
//      else
//      {
//         return 298.;
//      }
// };

