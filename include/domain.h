#if !defined(DOMAIN_H)
#define DOMAIN_H

#include "sdecomp.h"

typedef struct {
  sdecomp_info_t * info;
  // domain lengths
  double lengths[NDIMS];
  // degree of freedoms (number of Fourier modes)
  size_t p_glsizes[NDIMS];
  // number of Fourier modes in spectral domain
  // i.e. halved in the last dimension
  size_t s_glsizes[NDIMS];
  // local domain size for each pencil
  // spectral domain
  size_t s_x1_mysizes[NDIMS];
  size_t s_x1_offsets[NDIMS];
  // physical domain
#if NDIMS == 2
  size_t p_y1_mysizes[NDIMS];
  size_t p_y1_offsets[NDIMS];
#else
  size_t p_z1_mysizes[NDIMS];
  size_t p_z1_offsets[NDIMS];
#endif
  // wave numbers (k)
  int * restrict x1_xwaves;
  int * restrict x1_ywaves;
#if NDIMS == 3
  int * restrict x1_zwaves;
#endif
  // angular fequency = k times (2 pi / L)
  double * restrict x1_xfreqs;
  double * restrict x1_yfreqs;
#if NDIMS == 3
  double * restrict x1_zfreqs;
#endif
} domain_t;

extern int domain_init(
    const char dirname[],
    domain_t * domain
);

extern int domain_save(
    const char dirname[],
    const domain_t * domain
);

#endif // DOMAIN_H