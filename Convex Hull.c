include <unistd.h>


typedef struct {
  double x;
  double y;
} point_t;

typedef point_t* point_ptr_t;

/* Três pontos são uma curva na função anti-horária se ccw > 0,
 * uma curva horária se ccw < 0 e colineares de ccw = 0. Isso occore porque ccw
 * é um determinante que dá a área do triângulo formado por p1, p2 e p3
 */
static double
ccw(point_t* p1, point_t* p2, point_t* p3)
{
  return (p2->x - p1->x)*(p3->y - p1->y) - (p2->y - p1->y)*(p3->x - p1->x);
}

/* Retorna uma lista de pontos no convex hull em ordem anti-horária.
 * Nota: o último ponto na lista que é retornada é igual ao primeiro ponto.
 */
void
convex_hull(point_t* points, ssize_t npoints, point_ptr_t** out_hull, ssize_t* out_hullsize)
{
  point_ptr_t* hull;
  ssize_t i, t, k = 0;

  hull = *out_hull;

  /* lower hull */
  for (i = 0; i < npoints; ++i) {
    while (k >= 2 && ccw(hull[k-2], hull[k-1], &points[i]) <= 0) --k;
    hull[k++] = &points[i];
  }

  /* upper hull */
  for (i = npoints-2, t = k+1; i >= 0; --i) {
    while (k >= t && ccw(hull[k-2], hull[k-1], &points[i]) <= 0) --k;
    hull[k++] = &points[i];
  }

  *out_hull = hull;
  *out_hullsize = k;
}
