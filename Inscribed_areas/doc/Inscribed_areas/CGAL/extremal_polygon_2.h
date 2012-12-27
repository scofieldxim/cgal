namespace CGAL {

/*!
\ingroup PkgInscribedAreas

The function `extremal_polygon_2` computes a maximal 
`k`-gon that can be inscribed into a given convex polygon. The
criterion for maximality and some basic operations have to be
specified in an appropriate traits class parameter.

computes a maximal (as specified by `t`) inscribed `k`-gon of 
the convex polygon described by [`points_begin`, 
`points_end`), writes its vertices to `o` and returns the 
past-the-end iterator of this sequence. 

\pre the - at least three - points denoted by the range 
[`points_begin`, `points_end`) form the boundary of a 
convex polygon (oriented clock- or counterclockwise). 
\pre `k >= t.min_k()`.


\cgalRequires `Traits` is a model for `ExtremalPolygonTraits_2`. 
\cgalRequires Value type of `RandomAccessIterator` is `Traits::Point_2`. 
\cgalRequires `OutputIterator` accepts `Traits::Point_2` as value 
type. 


\sa `CGAL::maximum_area_inscribed_k_gon_2`
\sa `CGAL::maximum_perimeter_inscribed_k_gon_2`
\sa `ExtremalPolygonTraits_2` 
\sa `CGAL::monotone_matrix_search`

### Implementation ###

The implementation uses monotone matrix search 
\cite akmsw-gamsa-87 and has a worst case running time of \f$ O(k 
\cdot n + n \cdot \log n)\f$, where \f$ n\f$ is the number of vertices in 
\f$ P\f$. 

*/

template < class RandomAccessIterator, class OutputIterator, class Traits >
OutputIterator
extremal_polygon_2(
RandomAccessIterator points_begin,
RandomAccessIterator points_end,
int k,
OutputIterator o,
const Traits& t);


/*!
\ingroup PkgInscribedAreas

The function `maximum_area_inscribed_k_gon_2` computes a maximum area 
`k`-gon \f$ P_k\f$ that can be inscribed into a given convex polygon \f$ P\f$. 
Note that 
<UL> 
<LI>\f$ P_k\f$ is not unique in general, but it can be chosen in such a 
way that its vertices form a subset of the vertex set of \f$ P\f$ and 
<LI>the vertices of a maximum area `k`-gon, where the `k` vertices 
are to be drawn from a planar point set \f$ S\f$, lie on the convex 
hull of \f$ S\f$ i.e. a convex polygon. 
</UL> 

computes a maximum area inscribed `k`-gon of the convex polygon 
described by [`points_begin`, `points_end`), writes its 
vertices to `o` and returns the past-the-end iterator of this 
sequence. 

\pre the - at least three - points denoted by the range 
[`points_begin`, `points_end`) form the boundary of a 
convex polygon (oriented clock- or counterclockwise). 
\pre `k >= 3`.


\cgalRequires Value type of `RandomAccessIterator` is `K::Point_2` 
where `K` is a model for `Kernel`. 
\cgalRequires `OutputIterator` accepts the value type of 
`RandomAccessIterator` as value type. 


\sa `CGAL::maximum_perimeter_inscribed_k_gon_2`
\sa `ExtremalPolygonTraits_2` 
\sa `CGAL::Extremal_polygon_area_traits_2<K>`
\sa `CGAL::Extremal_polygon_perimeter_traits_2<K>`
\sa `CGAL::extremal_polygon_2`
\sa `CGAL::monotone_matrix_search`

### Implementation ###

The implementation uses monotone matrix search 
\cite akmsw-gamsa-87 and has a worst case running time of \f$ O(k 
\cdot n + n \cdot \log n)\f$, where \f$ n\f$ is the number of vertices in 
\f$ P\f$. 

### Example ###

The following code generates a random convex polygon 
`p` with ten vertices and computes the maximum area inscribed 
five-gon of `p`. 

\cgalExample{Inscribed_areas/extremal_polygon_2_area.cpp} 

*/

template < class RandomAccessIterator, class OutputIterator >
OutputIterator
maximum_area_inscribed_k_gon_2(
RandomAccessIterator points_begin,
RandomAccessIterator points_end,
int k,
OutputIterator o);

} /* namespace CGAL */

namespace CGAL {

/*!
\ingroup PkgInscribedAreas

The function `maximum_perimeter_inscribed_k_gon_2` computes a maximum perimeter 
`k`-gon \f$ P_k\f$ that can be inscribed into a given convex polygon \f$ P\f$. 
Note that 
<UL> 
<LI>\f$ P_k\f$ is not unique in general, but it can be chosen in such a 
way that its vertices form a subset of the vertex set of \f$ P\f$ and 
<LI>the vertices of a maximum perimeter `k`-gon, where the `k` 
vertices are to be drawn from a planar point set \f$ S\f$, lie on the 
convex hull of \f$ S\f$ i.e. a convex polygon. 
</UL> 

computes a maximum perimeter inscribed `k`-gon of the convex polygon 
described by [`points_begin`, `points_end`), writes its 
vertices to `o` and returns the past-the-end iterator of this 
sequence. 

\pre the - at least three - points denoted by the range 
[`points_begin`, `points_end`) form the boundary of a 
convex polygon (oriented clock- or counterclockwise). 
\pre `k >= 2`. 
 

\cgalRequires  Value type of `RandomAccessIterator` is `K::Point_2` 
where `K` is a model for `Kernel`. 
\cgalRequires There is a global function `K::FT CGAL::sqrt(K::FT)` 
defined that computes the squareroot of a number. 
\cgalRequires `OutputIterator` accepts the value type of 
`RandomAccessIterator` as value type. 


\sa `CGAL::maximum_area_inscribed_k_gon_2`
\sa `ExtremalPolygonTraits_2` 
\sa `CGAL::Extremal_polygon_area_traits_2<K>`
\sa `CGAL::Extremal_polygon_perimeter_traits_2<K>`
\sa `CGAL::extremal_polygon_2`
\sa `CGAL::monotone_matrix_search`

### Implementation ###

The implementation uses monotone matrix search 
\cite akmsw-gamsa-87 and has a worst case running time of \f$ O(k 
\cdot n + n \cdot \log n)\f$, where \f$ n\f$ is the number of vertices in 
\f$ P\f$. 

### Example ###

The following code generates a random convex polygon 
`p` with ten vertices and computes the maximum perimeter inscribed 
five-gon of `p`. 

\cgalExample{Inscribed_areas/extremal_polygon_2_perimeter.cpp} 

*/

template < class RandomAccessIterator, class OutputIterator >
OutputIterator
maximum_perimeter_inscribed_k_gon_2(
RandomAccessIterator points_begin,
RandomAccessIterator points_end,
int k,
OutputIterator o);

} /* namespace CGAL */
