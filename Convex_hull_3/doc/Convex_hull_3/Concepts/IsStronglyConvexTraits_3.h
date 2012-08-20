/*!
\ingroup PkgConvexHull3Concepts
\cgalconcept

Requirements of the traits class used by the function 
`CGAL::is_strongly_convex_3`, which is used for postcondition checking 
by `CGAL::convex_hull_3`. 

\hasModel CGAL::Convex_hull_traits_3<R> 
\hasModel All kernels of CGAL 

\sa `ConvexHullTraits_3` 
\sa `CGAL::is_strongly_convex_3` 

*/

class IsStronglyConvexTraits_3 {
public:

/// \name Types 
/// @{

/*! 
a 3D plane 
*/ 
typedef Hidden_type Plane_3; 

/*! 
a 3D point 
*/ 
typedef Hidden_type Point_3; 

/*! 
a 3D ray 
*/ 
typedef Hidden_type Ray_3; 

/*! 
a 3D triangle 
*/ 
typedef Hidden_type Triangle_3; 

/*! 
Function object type that provides 
`Ray_3 operator()(Point_3 p, Point_3 q)`, which constructs and returns 
the ray based at point `p` and passing though `q` 
*/ 
typedef Hidden_type Construct_ray_3; 

/*! 
Function object type that provides 
`Triangle_3 operator()(Point_3 p, Point_3 q, Point_3 r)`, which 
constructs and returns the triangle with vertices `p`, `q`, and 
`r` 
*/ 
typedef Hidden_type Construct_triangle_3; 

/*! 
Predicate object type that provides 
`bool operator()(Point_3 p, Point_3 q, Point_3 r, Point_3 s)`, which 
determines if points `p`, `q`, `r`, and `s` are coplanar 
or not 
*/ 
typedef Hidden_type Coplanar_3; 

/*! 
Function object type that provides 
`CGAL::Object operator()(Triangle_3 t, Ray_3 r)`, which 
returns `true` iff `t` and 
`r` intersect. 
*/ 
typedef Hidden_type Do_intersect_3; 

/*! 
Predicate object type that provides 
`bool operator()(Plane_3 h, Point_3 q)`, which determines of the point 
`q` is on the positive side of the halfspace `h` 
*/ 
typedef Hidden_type Has_on_positive_side_3; 

/*! 
Predicate object type that provides 
`Oriented_side operator()(Plane_3 p, Point_3 q)`, which determines 
the position of point `q` relative to plane `p` 
*/ 
typedef Hidden_type Oriented_side_3; 

/// @} 

/// \name Creation 
/// Only a copy constructor is required. 
/// @{

/*! 

*/ 
IsStronglyConvexTraits_3(IsStronglyConvexTraits_3& t); 

/// @} 

/*! \name Operations 
For each of the above function and predicate object types, 
`Func_obj_type`, a function must exist with the name 
`func_obj_type_object` that creates an instance of the function or 
predicate object type. For example: 
*/
/// @{

/*! 

*/ 
Construct_ray_3 construct_ray_3_object(); 

/// @}

}; /* end IsStronglyConvexTraits_3 */
