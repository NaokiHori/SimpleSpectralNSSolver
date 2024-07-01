#if !defined(FILEIO_INTERNAL_H)
#define FILEIO_INTERNAL_H

#if !defined(FILEIO_INTERNAL)
#error "do not include me externally"
#endif

extern char * fileio_internal_create_npyfname(
    const char dirname[],
    const char dsetname[]
);

extern size_t fileio_internal_r_npy_header(
    const char fname[],
    const size_t ndims,
    const size_t * shape,
    const char * dtype,
    const bool is_fortran_order
);

extern size_t fileio_internal_w_npy_header(
    const char fname[],
    const size_t ndims,
    const size_t * shape,
    const char dtype[],
    const bool is_fortran_order
);

#endif // FILEIO_INTERNAL_H
