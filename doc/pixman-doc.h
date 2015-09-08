/***********************************************************

Copyright 1987, 1998  The Open Group

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from The Open Group.

Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts.

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its
documentation for any purpose and without fee is hereby granted,
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in
supporting documentation, and that the name of Digital not be
used in advertising or publicity pertaining to distribution of the
software without specific, written prior permission.

DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
SOFTWARE.

******************************************************************/
/*
 * Copyright © 1998, 2004 Keith Packard
 * Copyright   2007 Red Hat, Inc.
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of Keith Packard not be used in
 * advertising or publicity pertaining to distribution of the software without
 * specific, written prior permission.  Keith Packard makes no
 * representations about the suitability of this software for any purpose.  It
 * is provided "as is" without express or implied warranty.
 *
 * KEITH PACKARD DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
 * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
 * EVENT SHALL KEITH PACKARD BE LIABLE FOR ANY SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef PIXMAN_H__
#define PIXMAN_H__

/**
 * @defgroup CAPI_PIXMAN_FRAMEWORK Pixman
 * @ingroup GRAPHICS_GROUP
*/

/**
 * @addtogroup CAPI_PIXMAN_FRAMEWORK
 * @brief A low-level pixel manipulation library providing features such as image compositing and trapezoid rasterization.
 *
 * @section CAPI_PIXMAN_FRAMEWORK_HEADER Required Header
 *   \#include <pixman.h>
 *
 * @section CAPI_PIXMAN_FRAMEWORK_OVERVIEW Overview
 * Pixman is a low-level software library for pixel manipulation, providing features such as image compositing and trapezoid
 * rasterization. Important users of pixman are the cairo graphics library and the X server.Pixman is implemented as a library
 * in the C programming language. It runs on many platforms, including Linux, BSD Derivatives, MacOS X, and Windows.
 *
 * Pixman is free and open source software. It is available to be redistributed and/or modified under the terms of the MIT license.
 * For additional reference, http://www.pixman.org/
 * @{
 */

#include <pixman-version.h>

#ifdef  __cplusplus
#define PIXMAN_BEGIN_DECLS extern "C" {
#define PIXMAN_END_DECLS }
#else
#define PIXMAN_BEGIN_DECLS
#define PIXMAN_END_DECLS
#endif

PIXMAN_BEGIN_DECLS

/*
 * Standard integers
 */

#if !defined (PIXMAN_DONT_DEFINE_STDINT)

#if defined (_SVR4) || defined (SVR4) || defined (__OpenBSD__) || defined (_sgi) || defined (__sun) || defined (sun) || defined (__digital__) || defined (__HP_cc)
#  include <inttypes.h>
/* VS 2010 (_MSC_VER 1600) has stdint.h */
#elif defined (_MSC_VER) && _MSC_VER < 1600

typedef __int8 int8_t;

typedef unsigned __int8 uint8_t;

typedef __int16 int16_t;

typedef unsigned __int16 uint16_t;

typedef __int32 int32_t;

typedef unsigned __int32 uint32_t;

typedef __int64 int64_t;

typedef unsigned __int64 uint64_t;

#elif defined (_AIX)
#  include <sys/inttypes.h>
#else
#  include <stdint.h>
#endif

#endif

/*! \var typedef int pixman_bool_t
	\brief Type definition for boolean
*/
typedef int pixman_bool_t;

/*
 * Fixpoint numbers
 */
/*! \var typedef int64_t pixman_fixed_32_32_t
	\brief Type definition for 64-bit fixed integer (digits stored as 32Bit + 32Bit)
*/
typedef int64_t			pixman_fixed_32_32_t;

/*! \var typedef pixman_fixed_32_32_t	pixman_fixed_48_16_t
	\brief Type definition for 64-bit fixed integer (digits stored as 48Bit + 16Bit)
*/
typedef pixman_fixed_32_32_t	pixman_fixed_48_16_t;

/*! \var typedef uint32_t		pixman_fixed_1_31_t
	\brief Type definition for 32-bit fixed integer (digits stored as 1Bit + 32Bit)
*/
typedef uint32_t		pixman_fixed_1_31_t;

/*! \var typedef uint32_t		pixman_fixed_1_16_t
	\brief Type definition for 32-bit fixed integer (digits stored as 1Bit + 16Bit)
*/
typedef uint32_t		pixman_fixed_1_16_t;

/*! \var typedef int32_t			pixman_fixed_16_16_t
	\brief Type definition for 32-bit fixed integer (digits stored as 16Bit + 16Bit)
*/
typedef int32_t			pixman_fixed_16_16_t;

/*! \var typedef pixman_fixed_16_16_t	pixman_fixed_t
	\brief Type definition for 32-bit fixed integer
*/
typedef pixman_fixed_16_16_t	pixman_fixed_t;

/*! \def pixman_fixed_e
	\brief Gets 32Bit fixed integer of 1
*/
#define pixman_fixed_e			((pixman_fixed_t) 1)

/*! \def pixman_fixed_1
	\brief Gets fixed integer of 1
*/
#define pixman_fixed_1			(pixman_int_to_fixed(1))

/*! \def pixman_fixed_1_minus_e
	\brief Gets the difference of fixed_1 and fixed_e
*/
#define pixman_fixed_1_minus_e		(pixman_fixed_1 - pixman_fixed_e)

/*! \def pixman_fixed_minus_1
	\brief Gets fixed integer of 1 complement
*/
#define pixman_fixed_minus_1		(pixman_int_to_fixed(-1))

/*! \def pixman_fixed_to_int
	\brief Converts a fixed integer to integer
*/
#define pixman_fixed_to_int(f)		((int) ((f) >> 16))

/*! \def pixman_int_to_fixed
	\brief Converts an integer to fixed integer
*/
#define pixman_int_to_fixed(i)		((pixman_fixed_t) ((i) << 16))

/*! \def pixman_fixed_to_double
	\brief Converts fixed integer to double
*/
#define pixman_fixed_to_double(f)	(double) ((f) / (double) pixman_fixed_1)

/*! \def pixman_double_to_fixed
	\brief Converts double to fixed integer
*/
#define pixman_double_to_fixed(d)	((pixman_fixed_t) ((d) * 65536.0))

/*! \def pixman_fixed_frac
	\brief Gets fixed version of fraction
*/
#define pixman_fixed_frac(f)		((f) & pixman_fixed_1_minus_e)

/*! \def pixman_fixed_floor
	\brief Gets floor of given value
*/
#define pixman_fixed_floor(f)		((f) & ~pixman_fixed_1_minus_e)

/*! \def pixman_fixed_ceil
	\brief Gets ceil of given value
*/
#define pixman_fixed_ceil(f)		pixman_fixed_floor ((f) + pixman_fixed_1_minus_e)

/*! \def pixman_fixed_fraction
	\brief Gets fixed fraction of given value
*/
#define pixman_fixed_fraction(f)	((f) & pixman_fixed_1_minus_e)

/*! \def pixman_fixed_mod_2
	\brief Gets 2 modulus of given fixed value
*/
#define pixman_fixed_mod_2(f)		((f) & (pixman_fixed1 | pixman_fixed_1_minus_e))

/*! \def pixman_max_fixed_48_16
	\brief Gets maximum value of pixman_fixed_48_16_t type
*/
#define pixman_max_fixed_48_16		((pixman_fixed_48_16_t) 0x7fffffff)

/*! \def pixman_min_fixed_48_16
	\brief Gets minimum value of pixman_fixed_48_16_t type
*/
#define pixman_min_fixed_48_16		(-((pixman_fixed_48_16_t) 1 << 31))

/*
 * Misc structs
 */

/*! \var typedef struct pixman_color pixman_color_t
	\brief Type definition for #pixman_color
*/
typedef struct pixman_color pixman_color_t;

/*! \var typedef struct pixman_point_fixed pixman_point_fixed_t
	\brief Type definition for #pixman_point_fixed
*/
typedef struct pixman_point_fixed pixman_point_fixed_t;

/*! \var typedef struct pixman_line_fixed pixman_line_fixed_t
	\brief Type definition for #pixman_line_fixed
*/
typedef struct pixman_line_fixed pixman_line_fixed_t;

/*! \var typedef struct pixman_vector pixman_vector_t
	\brief Type definition for #pixman_vector
*/
typedef struct pixman_vector pixman_vector_t;

/*! \var typedef struct pixman_transform pixman_transform_t
	\brief Type definition for #pixman_transform
*/
typedef struct pixman_transform pixman_transform_t;

/*! \struct pixman_color
	\brief Type used to represent color which comprises of Red, Green, Blue and Alpha components
*/
struct pixman_color
{
    uint16_t	red;		/**<Red component*/
    uint16_t    green;	/**<Green component*/
    uint16_t    blue;		/**<Blue component*/
    uint16_t    alpha;	/**<Alpha component*/
};

/*! \struct pixman_point_fixed
	\brief Type used to represent a point
*/
struct pixman_point_fixed
{
    pixman_fixed_t	x;	/**< X coordinate*/
    pixman_fixed_t	y;	/**< Y coordinate*/
};

/*! \struct pixman_line_fixed
	\brief Type used to represent a line
*/
struct pixman_line_fixed
{
    pixman_point_fixed_t	 p1, /**< Start Point*/
		p2;	/**< End Point*/
};

/*
 * Fixed point matrices
 */

/*! \struct pixman_vector
	\brief Type used to represent a 3-dimensional vector
*/
struct pixman_vector
{
    pixman_fixed_t	vector[3];	/**< 3 dimensional vector */
};

/*! \struct pixman_transform
	\brief Type used to represent a 3x3 transformation matrix
*/
struct pixman_transform
{
    pixman_fixed_t	matrix[3][3];		/**<3 dimensional matrix*/
};

/* forward declaration (sorry) */
/*! \struct pixman_box16
	\brief Type used to represent a box with 16-bit coordinates
*/
struct pixman_box16;

/*! \var typedef  union pixman_image		pixman_image_t
	\brief Type definition for pixman_image
*/
typedef  union pixman_image		pixman_image_t;

/**
 * @brief Initializes a given  matrix to an identity matrix
 * @param [in] matrix Matrix to be transformed
 * @see pixman_transform_is_identity()
 * @see pixman_f_transform_init_identity()
 */
void          pixman_transform_init_identity    (struct pixman_transform       *matrix);

/**
 * @brief Transforms a given point(3d) using the given transformation matrix
 * @param [in] transform Matrix used to transform
 * @param [in] vector A point represented as a 3d vector
 * @return 1 if transformation is successful, 0 otherwise
 * @see pixman_transform_point()
 * @see pixman_f_transform_point()
 * @see pixman_f_transform_point_3d()
 */
pixman_bool_t pixman_transform_point_3d         (const struct pixman_transform *transform,
						 struct pixman_vector          *vector);

/**
 * @brief Transforms a given point(2d) using the given transformation matrix
 * @param [in] transform Matrix used to transform
 * @param [in] vector A point represented as a 2d vector
 * @return 1 if transformation is successful, 0 otherwise
 * @see pixman_transform_point_3d()
 * @see pixman_f_transform_point()
 * @see pixman_f_transform_point_3d()
 */
pixman_bool_t pixman_transform_point            (const struct pixman_transform *transform,
						 struct pixman_vector          *vector);

/**
 * @brief Multiplies the given matrices.
 * @param [out] dst Resultant matrix after multiplication
 * @param [in] l Matrix used in multiplication
 * @param [in] r Matrix used in multiplication
 * @return 1 if multiplication is successful, 0 otherwise
 * @see pixman_f_transform_multiply()
 */
pixman_bool_t pixman_transform_multiply         (struct pixman_transform       *dst,
						 const struct pixman_transform *l,
						 const struct pixman_transform *r);

/**
 * @brief Initializes the matrix using the given scaling factors
 * @param [in] t Matrix used to transform
 * @param [in] sx X scaling factor
 * @param [in] sy Y scaling factor
 * @see pixman_f_transform_init_scale()
 * @see pixman_transform_is_scale()
 * @see pixman_transform_scale()
 */
void          pixman_transform_init_scale       (struct pixman_transform       *t,
						 pixman_fixed_t                 sx,
						 pixman_fixed_t                 sy);

/**
 * @brief Scales the forward/reverse matrix using given scaling factors
 * @details If forward matrix is set, resultant matrix will be "forward matrix * scale matrix". If reverse matrix is set, resultant matrix will be "scale matrix * reverse matrix".
 * @param [in] forward Matrix to be scaled using above criteria
 * @param [in] reverse Matrix to be scaled using above criteria
 * @param [in] sx X scaling factor
 * @param [in] sy Y scaling factor
 * @return pixman_bool_t is 1 if multiplication is successful, 0 otherwise
 * @see pixman_f_transform_init_scale()
 * @see pixman_transform_is_scale()
 * @see pixman_f_transform_scale()
 */
pixman_bool_t pixman_transform_scale            (struct pixman_transform       *forward,
						 struct pixman_transform       *reverse,
						 pixman_fixed_t                 sx,
						 pixman_fixed_t                 sy);

/**
 * @brief Initializes the matrix using given rotation factors
 * @param [in] t Matrix used to transform
 * @param [in] cos Cosine part of the rotation angle
 * @param [in] sin Sine part of the rotation angle
 * @see pixman_f_transform_init_rotate()
 */
void          pixman_transform_init_rotate      (struct pixman_transform       *t,
						 pixman_fixed_t                 cos,
						 pixman_fixed_t                 sin);

/**
 * @brief Rotates the forward/reverse matrix using given rotation factors
 * @details If forward matrix is set, resultant matrix will be "forward matrix * rotate matrix". If reverse matrix is set, resultant matrix will be "rotate matrix * reverse matrix".
 * @param [in] forward Matrix to be rotated using above criteria
 * @param [in] reverse Matrix to be rotated using above criteria
 * @param [in] c Cosine part of the rotation angle
 * @param [in] s Sine part of the rotation angle
 * @return pixman_bool_t is 1 if multiplication is successful, 0 otherwise
 * @see pixman_transform_init_rotate()
 * @see pixman_f_transform_init_rotate()
 * @see pixman_f_transform_rotate()
 */
pixman_bool_t pixman_transform_rotate           (struct pixman_transform       *forward,
						 struct pixman_transform       *reverse,
						 pixman_fixed_t                 c,
						 pixman_fixed_t                 s);

/**
 * @brief Initializes the matrix using given translation factors
 * @param [in] t Matrix used to transform
 * @param [in] tx Distance to translate in X direction
 * @param [in] ty Distance to translate in Y direction
 * @see pixman_transform_is_int_translate()
 * @see pixman_transform_translate()
 * @see pixman_f_transform_init_translate()
 * @see pixman_f_transform_translate()
 */
void          pixman_transform_init_translate   (struct pixman_transform       *t,
						 pixman_fixed_t                 tx,
						 pixman_fixed_t                 ty);

/**
 * @brief Translates the forward/reverse matrix by the given units
 * @details If forward matrix is set, resultant matrix will be "forward matrix * translation matrix". If reverse matrix is set, resultant matrix will be "translation matrix * reverse matrix".
 * @param [in] forward Matrix to be translated using above criteria
 * @param [in] reverse Matrix to be translated using above criteria
 * @param [in] tx Distance to translate in X direction
 * @param [in] ty Distance to translate in Y direction
 * @return pixman_bool_t is 1 if translation is successful, 0 otherwise
 * @see pixman_transform_is_int_translate()
 * @see pixman_transform_init_translate()
 * @see pixman_f_transform_init_translate()
 * @see pixman_f_transform_translate()
 */
pixman_bool_t pixman_transform_translate        (struct pixman_transform       *forward,
						 struct pixman_transform       *reverse,
						 pixman_fixed_t                 tx,
						 pixman_fixed_t                 ty);

/**
 * @brief Transforms the boundaries of given box
 * @param [in] matrix Matrix used to transform
 * @param [in] b Box to transform
 * @return pixman_bool_t is 1 if transformation is successful, 0 otherwise
 * @see pixman_f_transform_bounds()
 */
pixman_bool_t pixman_transform_bounds           (const struct pixman_transform *matrix,
						 struct pixman_box16           *b);

/**
 * @brief Inverts the given source matrix
 * @param [out] dst The resultant Inverted Matrix
 * @param [in] src Matrix to be inverted
 * @return pixman_bool_t is 1 if inversion is successful, 0 otherwise
 * @see pixman_f_transform_invert()
 */
pixman_bool_t pixman_transform_invert           (struct pixman_transform       *dst,
						 const struct pixman_transform *src);

/**
 * @brief Checks if the given transform matrix is an identity matrix or not
 * @param [in] t Matrix used to check
 * @return pixman_bool_t is 1 if given matrix is identity, 0 otherwise
 * @see pixman_transform_init_identity()
 * @see pixman_f_transform_init_identity()
 */
pixman_bool_t pixman_transform_is_identity      (const struct pixman_transform *t);

/**
 * @brief Checks if the given transform matrix is a scalar matrix or not
 * @param [in] t Matrix used to check
 * @return pixman_bool_t is 1 if given matrix is scalar, 0 otherwise
 * @see pixman_transform_init_scale()
 * @see pixman_transform_scale()
 * @see pixman_f_transform_init_scale()
 * @see pixman_f_transform_scale()
 */
pixman_bool_t pixman_transform_is_scale         (const struct pixman_transform *t);

/**
 * @brief Checks if the given transform matrix is a translated matrix or not
 * @param [in] t Matrix used to check
 * @return pixman_bool_t is 1 if given matrix is translated, 0 otherwise
 * @see pixman_transform_init_translate()
 * @see pixman_transform_translate()
 * @see pixman_f_transform_init_translate()
 * @see pixman_f_transform_translate()
 */
pixman_bool_t pixman_transform_is_int_translate (const struct pixman_transform *t);

/**
 * @brief Checks if the given transform is inverted in reference to another matrix
 * @param [in] a Matrix used to check
 * @param [in] b Matrix used to check
 * @return pixman_bool_t is 1 if given matrix is inverted, 0 otherwise
 * @see pixman_f_transform_invert()
 */
pixman_bool_t pixman_transform_is_inverse       (const struct pixman_transform *a,
						 const struct pixman_transform *b);


/*
 * Floating point matrices
 */

 /*! \struct pixman_f_vector
	\brief Type used to represent a 3-dimensional vector
*/
struct pixman_f_vector
{
    double  v[3];	/**<3 dimensional vector*/
};

/*! \struct pixman_f_transform
	\brief Type used to represent a 3x3 transformation matrix
*/
struct pixman_f_transform
{
    double  m[3][3];	/**<3d matrix*/
};

/**
 * @brief Will convert #pixman_f_transform matrix to #pixman_transform matrix
 * @param [out] t Resultant matrix
 * @param [in] ft Matrix to be converted
 * @return pixman_bool_t is 1 if conversion is successful, 0 otherwise
 * @see pixman_f_transform_from_pixman_transform()
 */
pixman_bool_t pixman_transform_from_pixman_f_transform (struct pixman_transform         *t,
							const struct pixman_f_transform *ft);

/**
 * @brief Will convert #pixman_transform matrix to #pixman_f_transform matrix
 * @param [out] ft Resultant matrix
 * @param [in] t Matrix to be converted
 * @see pixman_transform_from_pixman_transform()
 */
void          pixman_f_transform_from_pixman_transform (struct pixman_f_transform       *ft,
							const struct pixman_transform   *t);

/**
 * @brief Inverts the given source matrix
 * @param [out] dst The resultant Inverted Matrix
 * @param [in] src Matrix to be inverted
 * @return pixman_bool_t is 1 if inversion is successful, 0 otherwise
 * @see pixman_transform_invert()
 */
pixman_bool_t pixman_f_transform_invert                (struct pixman_f_transform       *dst,
							const struct pixman_f_transform *src);


/**
 * @brief Transforms a given point(2d) using the given transformation matrix
 * @param [in] t Matrix used to transform
 * @param [in] v A point represented as a 2d vector
 * @return 1 if transformation is successful, 0 otherwise
 * @see pixman_transform_point_3d()
 * @see pixman_transform_point()
 * @see pixman_f_transform_point_3d()
 */
pixman_bool_t pixman_f_transform_point                 (const struct pixman_f_transform *t,
							struct pixman_f_vector          *v);

/**
 * @brief Transforms a given point(3d) using the given transformation matrix
 * @param [in] t Matrix used to transform
 * @param [in] v A point represented as a 3d vector
 * @return 1 if transformation is successful, 0 otherwise
 * @see pixman_transform_point()
 * @see pixman_transform_point_3d()
 * @see pixman_f_transform_point()
 */
void          pixman_f_transform_point_3d              (const struct pixman_f_transform *t,
							struct pixman_f_vector          *v);

/**
 * @brief Multiplies the given matrices.
 * @param [out] dst Resultant matrix after multiplication
 * @param [in] l Matrix used in multiplication
 * @param [in] r Matrix used in multiplication
 * @return 1 if multiplication is successful, 0 otherwise
 * @see pixman_transform_multiply()
 */
void          pixman_f_transform_multiply              (struct pixman_f_transform       *dst,
							const struct pixman_f_transform *l,
							const struct pixman_f_transform *r);

/**
 * @brief Initializes the matrix using the given scaling factors
 * @param [in] t Matrix used to transform
 * @param [in] sx X scaling factor
 * @param [in] sy Y scaling factor
 * @see pixman_transform_init_scale()
 * @see pixman_transform_is_scale()
 * @see pixman_transform_scale()
 */
void          pixman_f_transform_init_scale            (struct pixman_f_transform       *t,
							double                           sx,
							double                           sy);

/**
 * @brief Scales the forward/reverse matrix using given scaling factors
 * @details If forward matrix is set, resultant matrix will be "forward matrix * scale matrix". If reverse matrix is set, resultant matrix will be "scale matrix * reverse matrix".
 * @param [in] forward Matrix to be scaled using above criteria
 * @param [in] reverse Matrix to be scaled using above criteria
 * @param [in] sx X scaling factor
 * @param [in] sy Y scaling factor
 * @return pixman_bool_t is 1 if multiplication is successful, 0 otherwise
 * @see pixman_f_transform_init_scale()
 * @see pixman_transform_is_scale()
 * @see pixman_transform_scale()
 */
pixman_bool_t pixman_f_transform_scale                 (struct pixman_f_transform       *forward,
							struct pixman_f_transform       *reverse,
							double                           sx,
							double                           sy);

/**
 * @brief Initializes the matrix using given rotation factors
 * @param [in] t Matrix used to transform
 * @param [in] cos Cosine part of the rotation angle
 * @param [in] sin Sine part of the rotation angle
 * @see pixman_transform_init_rotate()
 */
void          pixman_f_transform_init_rotate           (struct pixman_f_transform       *t,
							double                           cos,
							double                           sin);

/**
 * @brief Rotates the forward/reverse matrix using given rotation factors
 * @details If forward matrix is set, resultant matrix will be "forward matrix * rotate matrix". If reverse matrix is set, resultant matrix will be "rotate matrix * reverse matrix".
 * @param [in] forward Matrix to be rotated using above criteria
 * @param [in] reverse Matrix to be rotated using above criteria
 * @param [in] c Cosine part of the rotation angle
 * @param [in] s Sine part of the rotation angle
 * @return pixman_bool_t is 1 if multiplication is successful, 0 otherwise
 * @see pixman_transform_init_rotate()
 * @see pixman_transform_rotate()
 * @see pixman_f_transform_init_rotate()
 */
pixman_bool_t pixman_f_transform_rotate                (struct pixman_f_transform       *forward,
							struct pixman_f_transform       *reverse,
							double                           c,
							double                           s);

/**
 * @brief Initializes the matrix using given translation factors
 * @param [in] t Matrix used to transform
 * @param [in] tx Distance to translate in X direction
 * @param [in] ty Distance to translate in Y direction
 * @see pixman_transform_is_int_translate()
 * @see pixman_transform_translate()
 * @see pixman_transform_init_translate()
 * @see pixman_f_transform_translate()
 */
void          pixman_f_transform_init_translate        (struct pixman_f_transform       *t,
							double                           tx,
							double                           ty);

/**
 * @brief Translates the forward/reverse matrix by the given units
 * @details If forward matrix is set, resultant matrix will be "forward matrix * translation matrix". If reverse matrix is set, resultant matrix will be "translation matrix * reverse matrix".
 * @param [in] forward Matrix to be translated using above criteria
 * @param [in] reverse Matrix to be translated using above criteria
 * @param [in] tx Distance to translate in X direction
 * @param [in] ty Distance to translate in Y direction
 * @return pixman_bool_t is 1 if translation is successful, 0 otherwise
 * @see pixman_transform_is_int_translate()
 * @see pixman_transform_init_translate()
 * @see pixman_transform_translate()
 * @see pixman_f_transform_init_translate()
 */
pixman_bool_t pixman_f_transform_translate             (struct pixman_f_transform       *forward,
							struct pixman_f_transform       *reverse,
							double                           tx,
							double                           ty);

/**
 * @brief Transforms the boundaries of given box
 * @param [in] t Matrix used to transform
 * @param [in] b Box to transform
 * @return pixman_bool_t is 1 if transformation is successful, 0 otherwise
 * @see pixman_transform_bounds()
 */
pixman_bool_t pixman_f_transform_bounds                (const struct pixman_f_transform *t,
							struct pixman_box16             *b);

/**
 * @brief Initializes a given  matrix to an identity matrix
 * @param [in] t Matrix to be transformed
 * @see pixman_transform_is_identity()
 * @see pixman_transform_init_identity()
 */
void          pixman_f_transform_init_identity         (struct pixman_f_transform       *t);


/**
* Enumeration for bit repetition modes for images
*/
typedef enum
{
    PIXMAN_REPEAT_NONE,	/**< No repetition */
    PIXMAN_REPEAT_NORMAL,  /**< Normal Repetition */
    PIXMAN_REPEAT_PAD,		/**< Repeition with padding*/
    PIXMAN_REPEAT_REFLECT	/**< Repetition with image reflection */
} pixman_repeat_t;

/**
* Enumeration for bit repetition modes for images
*/
typedef enum
{
    PIXMAN_FILTER_FAST,		/**< Enables fast filter on images*/
    PIXMAN_FILTER_GOOD,		/**< Enables a good filter on images*/
    PIXMAN_FILTER_BEST,		/**< Enables a best  filter on images*/
    PIXMAN_FILTER_NEAREST,	/**< Enables the nearest pixel filter on images*/
    PIXMAN_FILTER_BILINEAR,	/**< Enables bilinear filter on images*/
    PIXMAN_FILTER_CONVOLUTION	/** Enables convoution filter on images<*/
} pixman_filter_t;

/**
* Enumeration to perform composition of images using different methods
*/
typedef enum
{
    PIXMAN_OP_CLEAR			= 0x00,	/**<Clears the given image*/
    PIXMAN_OP_SRC			= 0x01,	/**<Only Source image is displayed*/
    PIXMAN_OP_DST			= 0x02,	/**<Only Destination image is displayed*/
    PIXMAN_OP_OVER			= 0x03,	/**<Source Image is put over destination image*/
    PIXMAN_OP_OVER_REVERSE		= 0x04,	/**<Source Image is put over destination image and reversed*/
    PIXMAN_OP_IN			= 0x05,	/**<Clips the Source image which is in destination image*/
    PIXMAN_OP_IN_REVERSE		= 0x06,	/**<Clips the Source image which is in destination image and reversed*/
    PIXMAN_OP_OUT			= 0x07,	/**<Clips the Source image which is out of destination image*/
    PIXMAN_OP_OUT_REVERSE		= 0x08,	/**<Clips the Source image which is out of destination image and reversed*/
    PIXMAN_OP_ATOP			= 0x09,	/**<Places Source image on destination image and clips source image which is not on destination image*/
    PIXMAN_OP_ATOP_REVERSE		= 0x0a,	/**<Reverses the Atop operation of the image*/
    PIXMAN_OP_XOR			= 0x0b,	/**<Puts Source image over destination image and XORs the intersected bits of Src & Dst*/
    PIXMAN_OP_ADD			= 0x0c,	/**<Lighter Pixels of Src & Dst Images are intensified*/
    PIXMAN_OP_SATURATE			= 0x0d,	/**<Alpha component of overlapping source pixels will attain minimum limits */

    PIXMAN_OP_DISJOINT_CLEAR		= 0x10,	/**<Clears the given image, ignoring their alpha values*/
    PIXMAN_OP_DISJOINT_SRC		= 0x11,/**<Only Source image is displayed, ignoring their alpha values*/
    PIXMAN_OP_DISJOINT_DST		= 0x12,		/**<Only Destination image is displayed, ignoring their alpha values*/
    PIXMAN_OP_DISJOINT_OVER		= 0x13,	/**<Source Image is put over destination image, ignoring their alpha values*/
    PIXMAN_OP_DISJOINT_OVER_REVERSE	= 0x14,	/**<Source Image is put over destination image and reversed, ignoring their alpha values*/
    PIXMAN_OP_DISJOINT_IN		= 0x15,	/**<Clips the Source image which is in destination image, ignoring their alpha values*/
    PIXMAN_OP_DISJOINT_IN_REVERSE	= 0x16,	/**<Clips the Source image which is in destination image and reversed, ignoring their alpha values*/
    PIXMAN_OP_DISJOINT_OUT		= 0x17,	/**<Clips the Source image which is out of destination image, ignoring their alpha values*/
    PIXMAN_OP_DISJOINT_OUT_REVERSE	= 0x18,	/**<Clips the Source image which is out of destination image and reversed, ignoring their alpha values*/
    PIXMAN_OP_DISJOINT_ATOP		= 0x19,		/**<Places Source image on destination image and clips source image which is not on destination image, ignoring their alpha values*/
    PIXMAN_OP_DISJOINT_ATOP_REVERSE	= 0x1a,	/**<Reverses the Atop operation of the image, ignoring their alpha values*/
    PIXMAN_OP_DISJOINT_XOR		= 0x1b,	/**<Puts Source image over destination image and XORs the intersected bits of Src & Dst, ignoring their alpha values*/

    PIXMAN_OP_CONJOINT_CLEAR		= 0x20,	/**<Clears the given image, considering their alpha values*/
    PIXMAN_OP_CONJOINT_SRC		= 0x21,	/**<Only Source image is displayed, considering their alpha values*/
    PIXMAN_OP_CONJOINT_DST		= 0x22,		/**<Only Destination image is displayed, considering their alpha values*/
    PIXMAN_OP_CONJOINT_OVER		= 0x23,	/**<Source Image is put over destination image, considering their alpha values*/
    PIXMAN_OP_CONJOINT_OVER_REVERSE	= 0x24,	/**<Source Image is put over destination image and reversed, considering their alpha values*/
    PIXMAN_OP_CONJOINT_IN		= 0x25,	/**<Clips the Source image which is in destination image, considering their alpha values*/
    PIXMAN_OP_CONJOINT_IN_REVERSE	= 0x26,	/**<Clips the Source image which is in destination image and reversed, considering their alpha values*/
    PIXMAN_OP_CONJOINT_OUT		= 0x27,	/**<Clips the Source image which is out of destination image, considering their alpha values*/
    PIXMAN_OP_CONJOINT_OUT_REVERSE	= 0x28,/**<Clips the Source image which is out of destination image and reversed, considering their alpha values*/
    PIXMAN_OP_CONJOINT_ATOP		= 0x29,		/**<Places Source image on destination image and clips source image which is not on destination image, considering their alpha values*/
    PIXMAN_OP_CONJOINT_ATOP_REVERSE	= 0x2a,	/**<Reverses the Atop operation of the image, considering their alpha values*/
    PIXMAN_OP_CONJOINT_XOR		= 0x2b,	/**<Puts Source image over destination image and XORs the intersected bits of Src & Dst, considering their alpha values*/

    PIXMAN_OP_MULTIPLY                  = 0x30,	/**<Multiplies the pixels of Src & Dst Images*/
    PIXMAN_OP_SCREEN                    = 0x31,	/**<Compliments the composition of Src compliment and Dst compliment*/
    PIXMAN_OP_OVERLAY                   = 0x32,	/**<Light/dark pixels of Dst are preserved*/
    PIXMAN_OP_DARKEN                    = 0x33,	/**<Highlights the darker pixels of Src & Dst images*/
    PIXMAN_OP_LIGHTEN                   = 0x34,	/**<Highlights the lighter pixels of Src & Dst images*/
    PIXMAN_OP_COLOR_DODGE               = 0x35,	/**<Lighter pixels of Src is masked on Dst image*/
    PIXMAN_OP_COLOR_BURN                = 0x36,	/**<Darker pixels of Src is masked on Dst image*/
    PIXMAN_OP_HARD_LIGHT                = 0x37,	/**<Light/dark pixels of Src are preserved*/
    PIXMAN_OP_SOFT_LIGHT                = 0x38,	/**<Light/dark pixels of Src are preserved with highlights and shadows*/
    PIXMAN_OP_DIFFERENCE                = 0x39,	/**<Darker Pixels of Src & Dst Images are intensified*/
    PIXMAN_OP_EXCLUSION                 = 0x3a,	/**<Intersecting lighter pixels of Src & Dst are removed*/
    PIXMAN_OP_HSL_HUE			= 0x3b,	/**<Copies Hue of Src to Dst*/
    PIXMAN_OP_HSL_SATURATION		= 0x3c,	/**<Copies Saturation of Src to Dst*/
    PIXMAN_OP_HSL_COLOR			= 0x3d,	/**<Copies Hue and Saturation of Src to Dst*/
    PIXMAN_OP_HSL_LUMINOSITY		= 0x3e	/**<Copies Luminance of Src to Dst*/

#ifdef PIXMAN_USE_INTERNAL_API
    ,
    PIXMAN_N_OPERATORS,	/**<Tracks the count of existing operators*/
    PIXMAN_OP_NONE = PIXMAN_N_OPERATORS	/**<No composition*/
#endif
} pixman_op_t;

/*
 * Regions
 */

 /*! \var typedef struct pixman_region16_data	pixman_region16_data_t
	\brief Type definition for #pixman_region16_data
*/
typedef struct pixman_region16_data	pixman_region16_data_t;

 /*! \var typedef struct pixman_box16		pixman_box16_t
	\brief Type definition for #pixman_box16
*/
typedef struct pixman_box16		pixman_box16_t;

 /*! \var typedef struct pixman_rectangle16	pixman_rectangle16_t
	\brief Type definition for #pixman_rectangle16
*/
typedef struct pixman_rectangle16	pixman_rectangle16_t;

 /*! \var typedef struct pixman_region16		pixman_region16_t
	\brief Type definition for #pixman_region16
*/
typedef struct pixman_region16		pixman_region16_t;

/*! \struct pixman_region16_data
	\brief Type used to represent the data of a 16-bit region
*/
struct pixman_region16_data {
    long		size;	/**<Data size*/
    long		numRects;	/**<Number of rectangles*/
/*  pixman_box16_t	rects[size];   in memory but not explicitly declared */
};

/*! \struct pixman_rectangle16
	\brief Type used to represent a rectangle with 16-bit coordinates
*/
struct pixman_rectangle16
{
    int16_t	 x, 		/**<X coordinate*/
		y;		/**<Y coordinate*/
    uint16_t	width, 	/**<Width of rectangle*/
		height;		/**<Height of rectangle*/
};

/*! \struct pixman_box16
	\brief Type used to represent a box with 16-bit coordinates
*/
struct pixman_box16
{
    int16_t x1, 		/**<X coordinate of first point*/
		y1, 		/**<Y coordinate of first point*/
		x2, 		/**<X coordinate of second point*/
		y2;		/**<Y coordinate of second point*/
};

/*! \struct pixman_region16
	\brief Type used to represent a region with 16-bit coordinates
*/
struct pixman_region16
{
    pixman_box16_t          extents;	/**<Boundaries of the region*/
    pixman_region16_data_t *data;	/**<Data of the region*/
};

/**
* Enumeration to perform operations on regions
*/
typedef enum
{
    PIXMAN_REGION_OUT,	/**<Region excluding the overlapping area*/
    PIXMAN_REGION_IN,	/**<Region including the overlapping area*/
    PIXMAN_REGION_PART	/**<A part of the overlapping areas*/
} pixman_region_overlap_t;

/* This function exists only to make it possible to preserve
 * the X ABI - it should go away at first opportunity.
 */

 /**
 * @brief Initializes the 3 static pointers with addresses specified by structs
 * @param [in] empty_box Initial box with zero coordinates
 * @param [in] empty_data Null data
 * @param [in] broken_data Broken data
 */
void pixman_region_set_static_pointers (pixman_box16_t         *empty_box,
					pixman_region16_data_t *empty_data,
					pixman_region16_data_t *broken_data);

/* creation/destruction */
 /**
 * @brief Initializes the region
 * @param [in] region 16-bit region to be initialized
 * @see pixman_region_reset
 * @see pixman_region_clear
 * @see pixman_region_fini
 */
void                    pixman_region_init               (pixman_region16_t *region);

 /**
 * @brief Initializes the region with given rectangle
 * @param [in] region 16-bit region to be initialized
 * @param [in] x X coordinate
 * @param [in] y Y coordinate
 * @param [in] width width of rectangle
 * @param [in] height of rectangle
 * @see pixman_region_init_rects
 * @see pixman_region_union_rect
 * @see pixman_region_intersect_rect
 * @see pixman_region_contains_rectangle
 * @see pixman_region_n_rects
 * @see pixman_region_rectangles
 */
void                    pixman_region_init_rect          (pixman_region16_t *region,
							  int                x,
							  int                y,
							  unsigned int       width,
							  unsigned int       height);

 /**
 * @brief Initializes the region with given rectangles/boxes
 * @param [in] region 16-bit region to be initialized
 * @param [in] boxes An array of boxes
 * @param [in] count Number of boxes
 * @return 1 if operation is successful, 0 otherwise
 * @see pixman_region_init_rect
 * @see pixman_region_union_rect
 * @see pixman_region_intersect_rect
 * @see pixman_region_contains_rectangle
 * @see pixman_region_n_rects
 * @see pixman_region_rectangles
 */
pixman_bool_t           pixman_region_init_rects         (pixman_region16_t *region,
							  const pixman_box16_t *boxes,
							  int                count);

 /**
 * @brief Initializes the boundaries of the region
 * @param [in] region 16-bit region to be initialized
 * @param [in] extents 16-bit box to be initialized
 * @see pixman_region_extents
 */
void                    pixman_region_init_with_extents  (pixman_region16_t *region,
							  pixman_box16_t    *extents);

 /**
 * @brief Initializes the region with given image
 * @param [in] region 16-bit region to be initialized
 * @param [in] image image used to initialize the region
 */
void                    pixman_region_init_from_image    (pixman_region16_t *region,
							  pixman_image_t    *image);

 /**
 * @brief Finalizes the region
 * @param [in]  region 16-bit region to be initialized
 * @see pixman_region_reset
 * @see pixman_region_clear
 * @see pixman_region_init
 */
void                    pixman_region_fini               (pixman_region16_t *region);

/**
 * @brief Translates the given region by x and y distances
 * @param [in] region 16-bit region to be initialized
 * @param [in] x X coordinate
 * @param [in] y Y coordinate
 */
/* manipulation */
void                    pixman_region_translate          (pixman_region16_t *region,
							  int                x,
							  int                y);

/**
 * @brief Copies source region to destination
 * @param [out] dest 16-bit Destination region
 * @param [in] source 16-bit Source region to be copied
 * @return 1 if operation is successful, 0 otherwise
 */
pixman_bool_t           pixman_region_copy               (pixman_region16_t *dest,
							  pixman_region16_t *source);

/**
 * @brief Creates a region which is the intersection of 2 regions
 * @param [out] new_reg 16-bit Intersection region
 * @param [in] reg1 16-bit region
 * @param [in] reg2 16-bit region
 * @return 1 if operation is successful, 0 otherwise
 * @see pixman_region_intersect_rect
 */
pixman_bool_t           pixman_region_intersect          (pixman_region16_t *new_reg,
							  pixman_region16_t *reg1,
							  pixman_region16_t *reg2);

/**
 * @brief Creates a region which is the union of 2 regions
 * @param [out] new_reg 16-bit union region
 * @param [in] reg1 16-bit region
 * @param [in] reg2 16-bit region
 * @return 1 if operation is successful, 0 otherwise
 * @see pixman_region_union_rect
 */
pixman_bool_t           pixman_region_union              (pixman_region16_t *new_reg,
							  pixman_region16_t *reg1,
							  pixman_region16_t *reg2);

/**
 * @brief Creates a region which is union of a region and a rectangle
 * @param [out] dest 16-bit union region
 * @param [in] source 16-bit region
 * @param [in] x X coordinate
 * @param [in] y Y coordinate
 * @param [in] width width of rectangle
 * @param [in] height of rectangle
 * @return 1 if operation is successful, 0 otherwise
 * @see pixman_region_union
 */
pixman_bool_t           pixman_region_union_rect         (pixman_region16_t *dest,
							  pixman_region16_t *source,
							  int                x,
							  int                y,
							  unsigned int       width,
							  unsigned int       height);

/**
 * @brief Creates a region which is intersection of a region and a rectangle
 * @param [out] dest 16-bit intersection region
 * @param [in] source 16-bit region
 * @param [in] x X coordinate
 * @param [in] y Y coordinate
 * @param [in] width width of rectangle
 * @param [in] height of rectangle
 * @return 1 if operation is successful, 0 otherwise
 * @see pixman_region_intersect
 */
pixman_bool_t		pixman_region_intersect_rect     (pixman_region16_t *dest,
							  pixman_region16_t *source,
							  int                x,
							  int                y,
							  unsigned int       width,
							  unsigned int       height);

/**
 * @brief Creates a region which is the difference of 2 regions
 * @param [out] reg_d 16-bit region where result is stored [ reg_d = reg_s -reg_m ]
 * @param [in] reg_m 16-bit mask region
 * @param [in] reg_s 16-bit region to be subtracted
 * @return 1 if operation is successful, 0 otherwise
 */
pixman_bool_t           pixman_region_subtract           (pixman_region16_t *reg_d,
							  pixman_region16_t *reg_m,
							  pixman_region16_t *reg_s);

/**
 * @brief Creates a region by using the region in the given box
 * @param [out] new_reg 16-bit New inversed region
 * @param [in] reg1 16-bit region to be used
 * @param [out] inv_rect 16-bit rectangle that clips the region
 * @return 1 if operation is successful, 0 otherwise
 */
pixman_bool_t           pixman_region_inverse            (pixman_region16_t *new_reg,
							  pixman_region16_t *reg1,
							  pixman_box16_t    *inv_rect);

/**
 * @brief Checks whether a given point is there in the region and returns the associated box
 * @param [in] region 16-bit region
 * @param [in] x X coordinate
 * @param [in] y Y coordinate
 * @param [out] box Box in which point is found
 * @return 1 if operation is successful, 0 otherwise
 * @see pixman_region_contains_rectangle
 */
pixman_bool_t           pixman_region_contains_point     (pixman_region16_t *region,
							  int                x,
							  int                y,
							  pixman_box16_t    *box);

/**
 * @brief Checks whether a given rectangle is there in the region and returns the associated region
 * @param [in] region 16-bit region
 * @param [in] prect Rectangle whose presence needs to be checked
 * @return 16-bit Overlapping region
 * @see pixman_region_contains_point
 */
pixman_region_overlap_t pixman_region_contains_rectangle (pixman_region16_t *region,
							  pixman_box16_t    *prect);

/**
 * @brief Checks whether a given rectangle is empty
 * @param [in] region 16-bit region
 * @return 1 if operation is successful, 0 otherwise
 */
pixman_bool_t           pixman_region_not_empty          (pixman_region16_t *region);

/**
 * @brief Gives the extent of a given region
 * @param [in] region 16-bit region to be checked
 * @return 16-bit extent rectangle
 */
pixman_box16_t *        pixman_region_extents            (pixman_region16_t *region);

/**
 * @brief Gives the count of number of rectangles within the region
 * @param [in] region 16-bit region to be initialized
 * @return Rectangle count
 * @see pixman_region_rectangles
 */
int                     pixman_region_n_rects            (pixman_region16_t *region);

/**
 * @brief Gives the rectangles associated with the given region
 * @param [in] region 16-bit region to be checked
 * @param [out] n_rects Number of rectangles
 * @return Array of associated rectangles
 * @see pixman_region_n_rects
 */
pixman_box16_t *        pixman_region_rectangles         (pixman_region16_t *region,
							  int               *n_rects);

/**
 * @brief Checks if 2 regions are equal in their extents and rectangles
 * @param [in] region1 16-bit region to be checked
 * @param [in] region2 16-bit region to be checked
 * @return 1 if operation is successful, 0 otherwise
 */
pixman_bool_t           pixman_region_equal              (pixman_region16_t *region1,
							  pixman_region16_t *region2);

/**
 * @brief Validates the region in terms of extents and rectangles
 * @param [in] region 16-bit region to be checked
 * @return 1 if operation is successful, 0 otherwise
 */
pixman_bool_t           pixman_region_selfcheck          (pixman_region16_t *region);

/**
 * @brief Resets the region to a given box
 * @param [in] region 16-bit region to be reset
 * @param [in] box 16-bit box specifying the new dimensions of the region
 * @see pixman_region_clear
 */
void                    pixman_region_reset              (pixman_region16_t *region,
							  pixman_box16_t    *box);

/**
 * @brief Clears the given region
 * @param [in] region 16-bit region to be cleared
 * @see pixman_region_reset
 */
void			pixman_region_clear		 (pixman_region16_t *region);

/*
 * 32 bit regions
 */
/*! \var typedef struct pixman_region32_data	pixman_region32_data_t
	\brief Type definition for #pixman_region32_data
*/
typedef struct pixman_region32_data	pixman_region32_data_t;

/*! \var typedef struct pixman_box32		pixman_box32_t
	\brief Type definition for #pixman_box32
*/
typedef struct pixman_box32		pixman_box32_t;

/*! \var typedef struct pixman_rectangle32	pixman_rectangle32_t
	\brief Type definition for #pixman_rectangle32
*/
typedef struct pixman_rectangle32	pixman_rectangle32_t;

/*! \var typedef struct pixman_region32		pixman_region32_t
	\brief Type definition for #pixman_region32
*/
typedef struct pixman_region32		pixman_region32_t;

/*! \struct pixman_region32_data
	\brief Type used to represent the data of a 32-bit region
*/
struct pixman_region32_data {
    long		size;	/**<Data size*/
    long		numRects;		/**<Number of rectangles*/
/*  pixman_box32_t	rects[size];   in memory but not explicitly declared */
};

/*! \struct pixman_rectangle32
	\brief Type used to represent a rectangle with 32-bit coordinates
*/
struct pixman_rectangle32
{
    int32_t x, 			/**<X coordinate*/
		y;			/**<Y coordinate*/
    uint32_t width, 		/**<Width of rectangle*/
		height;		/**<Height of rectangle*/
};

/*! \struct pixman_box32
	\brief Type used to represent a box with 32-bit coordinates
*/
struct pixman_box32
{
    int32_t x1,	/**<X coordinate of first point*/
		y1, 	/**<Y coordinate of first point*/
		x2, 	/**<X coordinate of second point*/
		y2;	/**<Y coordinate of second point*/
};

/*! \struct pixman_region32
	\brief Type used to represent a region with 32-bit coordinates
*/
struct pixman_region32
{
    pixman_box32_t          extents;		/**<Boundaries of the rectangle*/
    pixman_region32_data_t  *data;		/**<Data of rectangle*/
};

/* creation/destruction */

 /**
 * @brief Initializes the region
 * @param [in] region 32-bit region to be initialized
 * @see pixman_region_reset
 * @see pixman_region_clear
 */
void                    pixman_region32_init               (pixman_region32_t *region);

 /**
 * @brief Initializes the region with given rectangle
 * @param [in] region 32-bit region to be initialized
 * @param [in] x X coordinate
 * @param [in] y Y coordinate
 * @param [in] width width of rectangle
 * @param [in] height of rectangle
 * @see pixman_region_init_rects
 * @see pixman_region_union_rect
 * @see pixman_region_intersect_rect
 * @see pixman_region_contains_rectangle
 * @see pixman_region_n_rects
 * @see pixman_region_rectangles
 */
void                    pixman_region32_init_rect          (pixman_region32_t *region,
							    int                x,
							    int                y,
							    unsigned int       width,
							    unsigned int       height);

 /**
 * @brief Initializes the region with given rectangles/boxes
 * @param [in] region 32-bit region to be initialized
 * @param [in] boxes An array of boxes
 * @param [in] count Number of boxes
 * @return 1 if operation is successful, 0 otherwise
 * @see pixman_region_init_rect
 * @see pixman_region_union_rect
 * @see pixman_region_intersect_rect
 * @see pixman_region_contains_rectangle
 * @see pixman_region_n_rects
 * @see pixman_region_rectangles
 */
pixman_bool_t           pixman_region32_init_rects         (pixman_region32_t *region,
							    const pixman_box32_t *boxes,
							    int                count);

 /**
 * @brief Initializes the boundaries of the region
 * @param [in] region 32-bit region to be initialized
 * @param [in] extents 32-bit box to be initialized
 * @see pixman_region_extents
 */
void                    pixman_region32_init_with_extents  (pixman_region32_t *region,
							    pixman_box32_t    *extents);

 /**
 * @brief Initializes the region with given image
 * @param [in] region 32-bit region to be initialized
 * @param [in] image image used to initialize the region
 */
void                    pixman_region32_init_from_image    (pixman_region32_t *region,
							    pixman_image_t    *image);

 /**
 * @brief Finalizes the region
 * @param [in]  region 32-bit region to be initialized
 * @see pixman_region_reset
 * @see pixman_region_clear
 * @see pixman_region_init
 */
void                    pixman_region32_fini               (pixman_region32_t *region);

/**
 * @brief Translates the given region by x and y distances
 * @param [in] region 32-bit region to be initialized
 * @param [in] x X coordinate
 * @param [in] y Y coordinate
 */
/* manipulation */
void                    pixman_region32_translate          (pixman_region32_t *region,
							    int                x,
							    int                y);

/**
 * @brief Copies source region to destination
 * @param [out] dest 32-bit Destination region
 * @param [in] source 32-bit Source region to be copied
 * @return 1 if operation is successful, 0 otherwise
 */
pixman_bool_t           pixman_region32_copy               (pixman_region32_t *dest,
							    pixman_region32_t *source);

/**
 * @brief Creates a region which is the intersection of 2 regions
 * @param [out] new_reg 32-bit Intersection region
 * @param [in] reg1 32-bit region
 * @param [in] reg2 32-bit region
 * @return 1 if operation is successful, 0 otherwise
 * @see pixman_region_intersect_rect
 */
pixman_bool_t           pixman_region32_intersect          (pixman_region32_t *new_reg,
							    pixman_region32_t *reg1,
							    pixman_region32_t *reg2);

/**
 * @brief Creates a region which is the union of 2 regions
 * @param [out] new_reg 32-bit union region
 * @param [in] reg1 32-bit region
 * @param [in] reg2 32-bit region
 * @return 1 if operation is successful, 0 otherwise
 * @see pixman_region_union_rect
 */
pixman_bool_t           pixman_region32_union              (pixman_region32_t *new_reg,
							    pixman_region32_t *reg1,
							    pixman_region32_t *reg2);

/**
 * @brief Creates a region which is intersection of a region and a rectangle
 * @param [out] dest 32-bit intersection region
 * @param [in] source 32-bit region
 * @param [in] x X coordinate
 * @param [in] y Y coordinate
 * @param [in] width width of rectangle
 * @param [in] height of rectangle
 * @return 1 if operation is successful, 0 otherwise
 * @see pixman_region_intersect
 */
pixman_bool_t		pixman_region32_intersect_rect     (pixman_region32_t *dest,
							    pixman_region32_t *source,
							    int                x,
							    int                y,
							    unsigned int       width,
							    unsigned int       height);

/**
 * @brief Creates a region which is union of a region and a rectangle
 * @param [out] dest 32-bit union region
 * @param [in] source 32-bit region 
 * @param [in] x X coordinate
 * @param [in] y Y coordinate
 * @param [in] width width of rectangle
 * @param [in] height of rectangle
 * @return 1 if operation is successful, 0 otherwise
 * @see pixman_region_union
 */
pixman_bool_t           pixman_region32_union_rect         (pixman_region32_t *dest,
							    pixman_region32_t *source,
							    int                x,
							    int                y,
							    unsigned int       width,
							    unsigned int       height);

/**
 * @brief Creates a region which is the difference of 2 regions
 * @param [out] reg_d 32-bit region where result is stored [ reg_d = reg_s -reg_m ]
 * @param [in] reg_m 32-bit mask region
 * @param [in] reg_s 32-bit region to be subtracted
 * @return 1 if operation is successful, 0 otherwise
 */
pixman_bool_t           pixman_region32_subtract           (pixman_region32_t *reg_d,
							    pixman_region32_t *reg_m,
							    pixman_region32_t *reg_s);

/**
 * @brief Creates a region by using the region in the given box
 * @param [out] new_reg 32-bit New inversed region
 * @param [in] reg1 32-bit region to be used
 * @param [in] inv_rect 32-bit rectangle that clips the region
 * @return 1 if operation is successful, 0 otherwise
 */
pixman_bool_t           pixman_region32_inverse            (pixman_region32_t *new_reg,
							    pixman_region32_t *reg1,
							    pixman_box32_t    *inv_rect);

/**
 * @brief Checks whether a given point is there in the region and returns the associated box
 * @param [in] region 32-bit region
 * @param [in] x X coordinate
 * @param [in] y Y coordinate
 * @param [out] box Box containing the point
 * @return 1 if operation is successful, 0 otherwise
 * @see pixman_region_contains_rectangle
 */
pixman_bool_t           pixman_region32_contains_point     (pixman_region32_t *region,
							    int                x,
							    int                y,
							    pixman_box32_t    *box);

/**
 * @brief Checks whether a given rectangle is there in the region and returns the associated region
 * @param [in] region 32-bit region
 * @param [in] prect Rectangle whose presence needs to be checked
 * @return 32-bit Overlapping region
 * @see pixman_region_contains_point
 */
pixman_region_overlap_t pixman_region32_contains_rectangle (pixman_region32_t *region,
							    pixman_box32_t    *prect);

/**
 * @brief Checks whether a given rectangle is empty
 * @param [in] region 32-bit region
 * @return 1 if operation is successful, 0 otherwise
 */
pixman_bool_t           pixman_region32_not_empty          (pixman_region32_t *region);

/**
 * @brief Gives the extent of a given region
 * @param [in] region 32-bit region to be checked
 * @return 32-bit extent rectangle
 */
pixman_box32_t *        pixman_region32_extents            (pixman_region32_t *region);

/**
 * @brief Gives the count of number of rectangles within the region
 * @param [in] region 32-bit region to be initialized
 * @return Rectangle count
 * @see pixman_region_rectangles
 */
int                     pixman_region32_n_rects            (pixman_region32_t *region);

/**
 * @brief Gives the rectangles associated with the given region
 * @param [in] region 32-bit region to be checked
 * @param [in] n_rects Number of rectangles
 * @return Array of associated rectangles
 * @see pixman_region_n_rects
 */
pixman_box32_t *        pixman_region32_rectangles         (pixman_region32_t *region,
							    int               *n_rects);

/**
 * @brief Checks if 2 regions are equal in their extents and rectangles
 * @param [in] region1 32-bit region to be checked
 * @param [in] region2 32-bit region to be checked
 * @return 1 if operation is successful, 0 otherwise
 */
pixman_bool_t           pixman_region32_equal              (pixman_region32_t *region1,
							    pixman_region32_t *region2);

/**
 * @brief Validates the region in terms of extents and rectangles
 * @param [in] region 32-bit region to be checked
 * @return 1 if operation is successful, 0 otherwise
 */
pixman_bool_t           pixman_region32_selfcheck          (pixman_region32_t *region);

/**
 * @brief Resets the region to a given box
 * @param [in] region 32-bit region to be reset
 * @param [in] box 32-bit box specifying the new dimensions of the region
 * @see pixman_region_clear
 */
void                    pixman_region32_reset              (pixman_region32_t *region,
							    pixman_box32_t    *box);

/**
 * @brief Clears the given region
 * @param [in] region 32-bit region to be cleared
 * @see pixman_region_reset
 */
void			pixman_region32_clear		   (pixman_region32_t *region);


/* Copy / Fill / Misc */
/**
 * @brief Copies source region to the destination region
 * @param [in] src_bits 32-Bit source data to copy
 * @param [out] dst_bits 32-Bit destination data
 * @param [in] src_stride Source stride
 * @param [in] dst_stride Destination stride
 * @param [in] src_bpp Source BPP
 * @param [in] dst_bpp Destination BPP
 * @param [in] src_x Source X
 * @param [in] src_y Source Y
 * @param [in] dest_x Destination X
 * @param [in] dest_y Destination Y
 * @param [in] width Width
 * @param [in] height Height
 * @return 1 if operation is successful, 0 otherwise
 */
pixman_bool_t pixman_blt                (uint32_t           *src_bits,
					 uint32_t           *dst_bits,
					 int                 src_stride,
					 int                 dst_stride,
					 int                 src_bpp,
					 int                 dst_bpp,
					 int                 src_x,
					 int                 src_y,
					 int                 dest_x,
					 int                 dest_y,
					 int                 width,
					 int                 height);

/**
 * @brief Fills the specified region
 * @param [in] bits Fill implementation
 * @param [in] stride Source stride
 * @param [in] bpp Source BPP
 * @param [in] x X coordinate
 * @param [in] y Y coordinate
 * @param [in] width Width
 * @param [in] height Height
 * @param [in] _xor XOR
 * @return 1 if operation is successful, 0 otherwise
 */
pixman_bool_t pixman_fill               (uint32_t           *bits,
					 int                 stride,
					 int                 bpp,
					 int                 x,
					 int                 y,
					 int                 width,
					 int                 height,
					 uint32_t            _xor);

/**
 * @brief Returns the version of the pixman in a single integer (PIXMAN_VERSION_ENCODE)
 * @return Pixman version
 * @see pixman_version_string
 */
int           pixman_version            (void);

/**
 * @brief Returns the version of the pixman as a string
 * @return Pixman version string
 * @see pixman_version
 */
const char*   pixman_version_string     (void);

/*
 * Images
 */
/*! \var typedef struct pixman_indexed		pixman_indexed_t
	\brief Type definition for #pixman_indexed
*/
typedef struct pixman_indexed		pixman_indexed_t;

/*! \var typedef struct pixman_gradient_stop	pixman_gradient_stop_t
	\brief Type definition for #pixman_gradient_stop
*/
typedef struct pixman_gradient_stop	pixman_gradient_stop_t;

/*! \var typedef uint32_t (* pixman_read_memory_func_t) (const void *src, int size)
	\brief Type definition for #pixman_read_memory_func_t
*/
typedef uint32_t (* pixman_read_memory_func_t) (const void *src, int size);

/*! \var typedef void     (* pixman_write_memory_func_t) (void *dst, uint32_t value, int size)
	\brief Type definition for #pixman_write_memory_func_t
*/
typedef void     (* pixman_write_memory_func_t) (void *dst, uint32_t value, int size);

/*! \var typedef void     (* pixman_image_destroy_func_t) (pixman_image_t *image, void *data)
	\brief Type definition for #pixman_image_destroy_func_t
*/
typedef void     (* pixman_image_destroy_func_t) (pixman_image_t *image, void *data);

/*! \struct pixman_gradient_stop
	\brief Type used to represent a gradient
*/
struct pixman_gradient_stop {
    pixman_fixed_t x;	/**<Point of gradient*/
    pixman_color_t color;	/**<Color of gradient*/
};

/*! \def PIXMAN_MAX_INDEXED
	\brief Specifies the maximum depth indexed
*/
#define PIXMAN_MAX_INDEXED  256 /* XXX depth must be <= 8 */

#if PIXMAN_MAX_INDEXED <= 256
/*! \var typedef uint8_t pixman_index_type
	\brief Type definition for uint8_t
*/
typedef uint8_t pixman_index_type;
#endif

/*! \struct pixman_indexed
	\brief Type used to represent a color index table
*/
struct pixman_indexed
{
    pixman_bool_t       color;	/**<Is colored*/
    uint32_t		rgba[PIXMAN_MAX_INDEXED];	/**<Possible color formats*/
    pixman_index_type	ent[32768];		/**< Lookup table for all entries*/
};

/*
 * While the protocol is generous in format support, the
 * sample implementation allows only packed RGB and GBR
 * representations for data to simplify software rendering,
 */

 /*! \def PIXMAN_FORMAT
	\brief Specifies the enumerator value for the given format
*/
#define PIXMAN_FORMAT(bpp,type,a,r,g,b)	(((bpp) << 24) |  \
					 ((type) << 16) | \
					 ((a) << 12) |	  \
					 ((r) << 8) |	  \
					 ((g) << 4) |	  \
					 ((b)))

 /*! \def PIXMAN_FORMAT_BPP
	\brief Specifies the BPP of the given format
*/
#define PIXMAN_FORMAT_BPP(f)	(((f) >> 24)       )

 /*! \def PIXMAN_FORMAT_TYPE
	\brief Specifies the type of the given format
*/
#define PIXMAN_FORMAT_TYPE(f)	(((f) >> 16) & 0xff)

 /*! \def PIXMAN_FORMAT_A
	\brief Specifies the Alpha component of the given format
*/
#define PIXMAN_FORMAT_A(f)	(((f) >> 12) & 0x0f)

 /*! \def PIXMAN_FORMAT_R
	\brief Specifies the Red component of the given format
*/
#define PIXMAN_FORMAT_R(f)	(((f) >>  8) & 0x0f)

 /*! \def PIXMAN_FORMAT_G
	\brief Specifies the green component of the given format
*/
#define PIXMAN_FORMAT_G(f)	(((f) >>  4) & 0x0f)

 /*! \def PIXMAN_FORMAT_B
	\brief Specifies the blue component of the given format
*/
#define PIXMAN_FORMAT_B(f)	(((f)      ) & 0x0f)

 /*! \def PIXMAN_FORMAT_RGB
	\brief Specifies the RGB components of the given format
*/
#define PIXMAN_FORMAT_RGB(f)	(((f)      ) & 0xfff)

 /*! \def PIXMAN_FORMAT_VIS
	\brief Specifies the RGBA components of the given format
*/
#define PIXMAN_FORMAT_VIS(f)	(((f)      ) & 0xffff)

 /*! \def PIXMAN_FORMAT_DEPTH
	\brief Specifies the depth of the given format
*/
#define PIXMAN_FORMAT_DEPTH(f)	(PIXMAN_FORMAT_A(f) +	\
				 PIXMAN_FORMAT_R(f) +	\
				 PIXMAN_FORMAT_G(f) +	\
				 PIXMAN_FORMAT_B(f))

 /*! \def PIXMAN_TYPE_OTHER
	\brief Specifies the format OTHER
*/
#define PIXMAN_TYPE_OTHER	0

 /*! \def PIXMAN_TYPE_A
	\brief Specifies the  format A
*/
#define PIXMAN_TYPE_A		1

 /*! \def PIXMAN_TYPE_ARGB
	\brief Specifies the  format ARGB
*/
#define PIXMAN_TYPE_ARGB	2

 /*! \def PIXMAN_TYPE_ABGR
	\brief Specifies the  format ABGR
*/
#define PIXMAN_TYPE_ABGR	3

 /*! \def PIXMAN_TYPE_COLOR
	\brief Specifies the  COLOR format
*/
#define PIXMAN_TYPE_COLOR	4

 /*! \def PIXMAN_TYPE_GRAY
	\brief Specifies the  format GRAY
*/
#define PIXMAN_TYPE_GRAY	5

 /*! \def PIXMAN_TYPE_YUY2
	\brief Specifies the  format YUY2
*/
#define PIXMAN_TYPE_YUY2	6

 /*! \def PIXMAN_TYPE_YV12
	\brief Specifies the  format YV12
*/
#define PIXMAN_TYPE_YV12	7

 /*! \def PIXMAN_TYPE_BGRA
	\brief Specifies the  format BGRA
*/
#define PIXMAN_TYPE_BGRA	8

 /*! \def PIXMAN_TYPE_RGBA
	\brief Specifies the  format RGBA
*/
#define PIXMAN_TYPE_RGBA	9

 /*! \def PIXMAN_TYPE_ARGB_SRGB
	\brief Specifies the  format ARGB_SRGB
*/
#define PIXMAN_TYPE_ARGB_SRGB	10

 /*! \def PIXMAN_FORMAT_COLOR
	\brief Specifies whether given format is color or not
*/
#define PIXMAN_FORMAT_COLOR(f)				\
	(PIXMAN_FORMAT_TYPE(f) == PIXMAN_TYPE_ARGB ||	\
	 PIXMAN_FORMAT_TYPE(f) == PIXMAN_TYPE_ABGR ||	\
	 PIXMAN_FORMAT_TYPE(f) == PIXMAN_TYPE_BGRA ||	\
	 PIXMAN_FORMAT_TYPE(f) == PIXMAN_TYPE_RGBA)

/* 32bpp formats */
/**
* Enumeration for different color formats
*/
typedef enum {
    PIXMAN_a8r8g8b8 =	 PIXMAN_FORMAT(32,PIXMAN_TYPE_ARGB,8,8,8,8),	/**<Color Format ARGB8888*/
    PIXMAN_x8r8g8b8 =	 PIXMAN_FORMAT(32,PIXMAN_TYPE_ARGB,0,8,8,8),	/**<Color Format RGB888*/
    PIXMAN_a8b8g8r8 =	 PIXMAN_FORMAT(32,PIXMAN_TYPE_ABGR,8,8,8,8),	/**<Color Format ABGR8888*/
    PIXMAN_x8b8g8r8 =	 PIXMAN_FORMAT(32,PIXMAN_TYPE_ABGR,0,8,8,8),	/**<Color Format BGR888*/
    PIXMAN_b8g8r8a8 =	 PIXMAN_FORMAT(32,PIXMAN_TYPE_BGRA,8,8,8,8),	/**<Color Format BGRA8888*/
    PIXMAN_b8g8r8x8 =	 PIXMAN_FORMAT(32,PIXMAN_TYPE_BGRA,0,8,8,8),	/**<Color Format GRA888*/
    PIXMAN_r8g8b8a8 =	 PIXMAN_FORMAT(32,PIXMAN_TYPE_RGBA,8,8,8,8),	/**<Color Format RGBA8888*/
    PIXMAN_r8g8b8x8 =	 PIXMAN_FORMAT(32,PIXMAN_TYPE_RGBA,0,8,8,8),	/**<Color Format GBA888*/
    PIXMAN_x14r6g6b6 =	 PIXMAN_FORMAT(32,PIXMAN_TYPE_ARGB,0,6,6,6),	/**<Color Format RGB666*/
    PIXMAN_x2r10g10b10 = PIXMAN_FORMAT(32,PIXMAN_TYPE_ARGB,0,10,10,10),	/**<Color Format RGB-10-10-10*/
    PIXMAN_a2r10g10b10 = PIXMAN_FORMAT(32,PIXMAN_TYPE_ARGB,2,10,10,10),	/**<Color Format ARGB-2-10-10-10*/
    PIXMAN_x2b10g10r10 = PIXMAN_FORMAT(32,PIXMAN_TYPE_ABGR,0,10,10,10),	/**<Color Format BGR-10-10-10*/
    PIXMAN_a2b10g10r10 = PIXMAN_FORMAT(32,PIXMAN_TYPE_ABGR,2,10,10,10),	/**<Color Format ABGR-2-10-10-10*/

/* sRGB formats */
    PIXMAN_a8r8g8b8_sRGB = PIXMAN_FORMAT(32,PIXMAN_TYPE_ARGB_SRGB,8,8,8,8),	/**<Color Format SRGB8888*/

/* 24bpp formats */
    PIXMAN_r8g8b8 =	 PIXMAN_FORMAT(24,PIXMAN_TYPE_ARGB,0,8,8,8),	/**<Color Format RGB888*/
    PIXMAN_b8g8r8 =	 PIXMAN_FORMAT(24,PIXMAN_TYPE_ABGR,0,8,8,8),	/**<Color Format BGR888*/

/* 16bpp formats */
    PIXMAN_r5g6b5 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_ARGB,0,5,6,5),	/**<Color Format RGB565*/
    PIXMAN_b5g6r5 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_ABGR,0,5,6,5),	/**<Color Format BGR565*/

    PIXMAN_a1r5g5b5 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_ARGB,1,5,5,5),	/**<Color Format ARGB1555*/
    PIXMAN_x1r5g5b5 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_ARGB,0,5,5,5),	/**<Color Format RGB555*/
    PIXMAN_a1b5g5r5 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_ABGR,1,5,5,5),	/**<Color Format ABGR1555*/
    PIXMAN_x1b5g5r5 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_ABGR,0,5,5,5),	/**<Color Format BGR555*/
    PIXMAN_a4r4g4b4 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_ARGB,4,4,4,4),	/**<Color Format ARGB4444*/
    PIXMAN_x4r4g4b4 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_ARGB,0,4,4,4),	/**<Color Format RGB444*/
    PIXMAN_a4b4g4r4 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_ABGR,4,4,4,4),	/**<Color Format ABGR4444*/
    PIXMAN_x4b4g4r4 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_ABGR,0,4,4,4),	/**<Color Format BGR444*/

/* 8bpp formats */
    PIXMAN_a8 =		 PIXMAN_FORMAT(8,PIXMAN_TYPE_A,8,0,0,0),	/**<Color Format A8*/
    PIXMAN_r3g3b2 =	 PIXMAN_FORMAT(8,PIXMAN_TYPE_ARGB,0,3,3,2),	/**<Color Format RGB332*/
    PIXMAN_b2g3r3 =	 PIXMAN_FORMAT(8,PIXMAN_TYPE_ABGR,0,3,3,2),	/**<Color Format BGR332*/
    PIXMAN_a2r2g2b2 =	 PIXMAN_FORMAT(8,PIXMAN_TYPE_ARGB,2,2,2,2),	/**<Color Format ARGB2222*/
    PIXMAN_a2b2g2r2 =	 PIXMAN_FORMAT(8,PIXMAN_TYPE_ABGR,2,2,2,2),	/**<Color Format ABGR2222*/

    PIXMAN_c8 =		 PIXMAN_FORMAT(8,PIXMAN_TYPE_COLOR,0,0,0,0),	/**<Color Format Color8*/
    PIXMAN_g8 =		 PIXMAN_FORMAT(8,PIXMAN_TYPE_GRAY,0,0,0,0),	/**<Color Format Gray8*/

    PIXMAN_x4a4 =	 PIXMAN_FORMAT(8,PIXMAN_TYPE_A,4,0,0,0),	/**<Color Format A44*/

    PIXMAN_x4c4 =	 PIXMAN_FORMAT(8,PIXMAN_TYPE_COLOR,0,0,0,0),	/**<Color Format Color44*/
    PIXMAN_x4g4 =	 PIXMAN_FORMAT(8,PIXMAN_TYPE_GRAY,0,0,0,0),	/**<Color Format Gray44*/

/* 4bpp formats */
    PIXMAN_a4 =		 PIXMAN_FORMAT(4,PIXMAN_TYPE_A,4,0,0,0),	/**<Color Format A4*/
    PIXMAN_r1g2b1 =	 PIXMAN_FORMAT(4,PIXMAN_TYPE_ARGB,0,1,2,1),	/**<Color Format RGB121*/
    PIXMAN_b1g2r1 =	 PIXMAN_FORMAT(4,PIXMAN_TYPE_ABGR,0,1,2,1),	/**<Color Format BGR121*/
    PIXMAN_a1r1g1b1 =	 PIXMAN_FORMAT(4,PIXMAN_TYPE_ARGB,1,1,1,1),	/**<Color Format ARGB1111*/
    PIXMAN_a1b1g1r1 =	 PIXMAN_FORMAT(4,PIXMAN_TYPE_ABGR,1,1,1,1),	/**<Color Format ABGR1111*/

    PIXMAN_c4 =		 PIXMAN_FORMAT(4,PIXMAN_TYPE_COLOR,0,0,0,0),	/**<Color Format Color4*/
    PIXMAN_g4 =		 PIXMAN_FORMAT(4,PIXMAN_TYPE_GRAY,0,0,0,0),	/**<Color Format Gray4*/

/* 1bpp formats */
    PIXMAN_a1 =		 PIXMAN_FORMAT(1,PIXMAN_TYPE_A,1,0,0,0),	/**<Color Format A1*/

    PIXMAN_g1 =		 PIXMAN_FORMAT(1,PIXMAN_TYPE_GRAY,0,0,0,0),	/**<Color Format Gray1*/

/* YUV formats */
    PIXMAN_yuy2 =	 PIXMAN_FORMAT(16,PIXMAN_TYPE_YUY2,0,0,0,0),	/**<Color Format YUY2*/
    PIXMAN_yv12 =	 PIXMAN_FORMAT(12,PIXMAN_TYPE_YV12,0,0,0,0)	/**<Color Format YV12*/
} pixman_format_code_t;

/* Querying supported format values. */

/**
 * @brief Checks whether the given format is supported in destination
 * @param [in] format Color format to be checked
 * @return 1 if format is supported, 0 otherwise
 * @see pixman_format_supported_source
 */
pixman_bool_t pixman_format_supported_destination (pixman_format_code_t format);

/**
 * @brief Checks whether the given format is supported in source
 * @param [in] format Color format to be checked
 * @return 1 if format is supported, 0 otherwise
 * @see pixman_format_supported_destination
 */
pixman_bool_t pixman_format_supported_source      (pixman_format_code_t format);


/* Constructors */

/**
 * @brief Creates an image which solid-filled with the given color
 * @param [in] color Fill color
 * @return Colored image
 */
pixman_image_t *pixman_image_create_solid_fill       (const pixman_color_t         *color);

/**
 * @brief Creates an image with a linear gradient at specified points & stops
 * @param [in] p1 Fixed point for gradient
 * @param [in] p2 Fixed point for gradient
 * @param [in] stops Array of stops in gradient
 * @param [in] n_stops Number of stops
 * @return Image with linear gradient
 * @see pixman_image_create_radial_gradient
 * @see pixman_image_create_conical_gradient
 */
pixman_image_t *pixman_image_create_linear_gradient  (const pixman_point_fixed_t   *p1,
						      const pixman_point_fixed_t   *p2,
						      const pixman_gradient_stop_t *stops,
						      int                           n_stops);

/**
 * @brief Creates an image with a radial gradient at specified radii & stops
 * @param [in] inner Fixed point for radial gradient
 * @param [in] outer Fixed point for radial gradient
 * @param [in] inner_radius Inner radius of the gradient
 * @param [in] outer_radius Outer radius of the gradient
 * @param [in] stops Array of stops in gradient
 * @param [in] n_stops Number of stops
 * @return Image with radial gradient
 * @see pixman_image_create_linear_gradient
 * @see pixman_image_create_conical_gradient
 */
pixman_image_t *pixman_image_create_radial_gradient  (const pixman_point_fixed_t   *inner,
						      const pixman_point_fixed_t   *outer,
						      pixman_fixed_t                inner_radius,
						      pixman_fixed_t                outer_radius,
						      const pixman_gradient_stop_t *stops,
						      int                           n_stops);

/**
 * @brief Creates an image with a conical gradient at specified angle & stops
 * @param [in] center Central point for the gradient
 * @param [in] angle Angle for the gradient
 * @param [in] stops Array of stops in gradient
 * @param [in] n_stops Number of stops
 * @return Image with conical gradient
 * @see pixman_image_create_linear_gradient
 * @see pixman_image_create_radial_gradient
 */
pixman_image_t *pixman_image_create_conical_gradient (const pixman_point_fixed_t   *center,
						      pixman_fixed_t                angle,
						      const pixman_gradient_stop_t *stops,
						      int                           n_stops);

/**
 * @brief Creates an image with given buffer and dimensions.If buffer is NULL, then initialized to 0.
 * @param [in] format Color format
 * @param [in] width Width of image
 * @param [in] height Height of image
 * @param [in] bits Buffer
 * @param [in] rowstride_bytes Row stride in bytes
 * @return Image created using the given buffer
 * @see pixman_image_create_bits_no_clear
 */
pixman_image_t *pixman_image_create_bits             (pixman_format_code_t          format,
						      int                           width,
						      int                           height,
						      uint32_t                     *bits,
						      int                           rowstride_bytes);

/**
 * @brief Creates an image with given buffer and dimensions. If buffer is NULL, then not initialized
 * @param [in] format Color format
 * @param [in] width Width of image
 * @param [in] height Height of image
 * @param [in] bits Buffer
 * @param [in] rowstride_bytes Row stride in bytes
 * @return Image created using the given buffer
 * @see pixman_image_create_bits_no_clear
 */
pixman_image_t *pixman_image_create_bits_no_clear    (pixman_format_code_t format,
						      int                  width,
						      int                  height,
						      uint32_t *           bits,
						      int                  rowstride_bytes);

/**
 * @brief Increases the reference count for the given image
 * @param [in] image Image to be referenced
 * @return Image after being referenced
 * @see pixman_image_unref
 */

/* Destructor */
pixman_image_t *pixman_image_ref                     (pixman_image_t               *image);

/**
 * @brief Decreases the reference count for the given image
 * @param [in] image Image to be dereferenced
 * @return 1 if operation is successful, 0 otherwise
 * @see pixman_image_ref
 */
pixman_bool_t   pixman_image_unref                   (pixman_image_t               *image);

/**
 * @brief Sets the destroy function pointer and data for the given image
 * @param [in] image Pixman Image
 * @param [in] function Destroy function's reference
 * @param [in] data Destroy function's data
 * @see pixman_image_get_destroy_data
 */
void		pixman_image_set_destroy_function    (pixman_image_t		   *image,
						      pixman_image_destroy_func_t   function,
						      void			   *data);

/**
 * @brief Gets the destroy function's data for the given image
 * @param [in] image Pixman Image
 * @return Given image's destroy data
 * @see pixman_image_set_destroy_function
 * @see pixman_image_get_data
 */
void *		pixman_image_get_destroy_data        (pixman_image_t		   *image);

/**
 * @brief Sets 16-bit clip region in the given image
 * @param [in] image Pixman Image
 * @param [in] region 16-bit clipped region
 * @return 1 if operation is successful, 0 otherwise
 * @see pixman_image_set_clip_region32
 * @see pixman_image_set_has_client_clip
 * @see pixman_image_set_source_clipping
 */

/* Set properties */
pixman_bool_t   pixman_image_set_clip_region         (pixman_image_t               *image,
						      pixman_region16_t            *region);

/**
 * @brief Sets 32-bit clip region in the given image
 * @param [in] image Pixman Image
 * @param [in] region 32-bit clipped region
 * @return 1 if operation is successful, 0 otherwise
 * @see pixman_image_set_clip_region
 * @see pixman_image_set_has_client_clip
 * @see pixman_image_set_source_clipping
 */
pixman_bool_t   pixman_image_set_clip_region32       (pixman_image_t               *image,
						      pixman_region32_t            *region);

/**
 * @brief Sets the client clip status for the given image
 * @param [in] image Pixman Image
 * @param [in] clien_clip Clip status
 * @see pixman_image_set_clip_region
 * @see pixman_image_set_clip_region32
 * @see pixman_image_set_source_clipping
 */
void		pixman_image_set_has_client_clip     (pixman_image_t               *image,
						      pixman_bool_t		    clien_clip);

/**
 * @brief Applies the given transformation matrix on the given image
 * @param [in] image Pixman Image
 * @param [in] transform Transformation matrix
 * @return 1 if operation is successful, 0 otherwise
 */
pixman_bool_t   pixman_image_set_transform           (pixman_image_t               *image,
						      const pixman_transform_t     *transform);

/**
 * @brief Sets a repeating mode for the given image
 * @param [in] image Pixman Image
 * @param [in] repeat Repeating mode
 */
void            pixman_image_set_repeat              (pixman_image_t               *image,
						      pixman_repeat_t               repeat);

/**
 * @brief Sets a filter mode for the given image
 * @param [in] image Pixman Image
 * @param [in] filter Filter to be applied
 * @param [in] filter_params Filter parameters to be applied
 * @param [in] n_filter_params Number of filter parameters
 */
pixman_bool_t   pixman_image_set_filter              (pixman_image_t               *image,
						      pixman_filter_t               filter,
						      const pixman_fixed_t         *filter_params,
						      int                           n_filter_params);

/**
 * @brief Sets the source clipping for the given image
 * @param [in] image Pixman Image
 * @param [in] source_clipping Clip status
 */
void		pixman_image_set_source_clipping     (pixman_image_t		   *image,
						      pixman_bool_t                 source_clipping);

/**
 * @brief Sets alpha map for the given image
 * @param [in] image Pixman Image
 * @param [in] alpha_map Alpha map reference
 * @param [in] x X coordinate
 * @param [in] y Y coordinate
 * @see pixman_image_set_component_alpha
 * @see pixman_image_get_component_alpha
 */
void            pixman_image_set_alpha_map           (pixman_image_t               *image,
						      pixman_image_t               *alpha_map,
						      int16_t                       x,
						      int16_t                       y);

/**
 * @brief Sets component alpha for the given image
 * @param [in] image Pixman Image
 * @param [in] component_alpha Component alpha status
 * @see pixman_image_set_component_alpha
 * @see pixman_image_get_component_alpha
 */
void            pixman_image_set_component_alpha     (pixman_image_t               *image,
						      pixman_bool_t                 component_alpha);

/**
 * @brief Gets component alpha for the given image
 * @param [in] image Pixman Image
 * @return 1 if component alpha is set, 0 otherwise
 * @see pixman_image_set_component_alpha
 * @see pixman_image_set_alpha_map
 */
pixman_bool_t   pixman_image_get_component_alpha     (pixman_image_t               *image);

/**
 * @brief Sets read and write accessors for the given image
 * @param [in] image Pixman Image
 * @param [in] read_func Read function reference
 * @param [in] write_func Write function reference
 */
void		pixman_image_set_accessors	     (pixman_image_t		   *image,
						      pixman_read_memory_func_t	    read_func,
						      pixman_write_memory_func_t    write_func);

/**
 * @brief Updates the index of the given image
 * @param [in] image Pixman Image
 * @param [in] indexed Index
 */
void		pixman_image_set_indexed	     (pixman_image_t		   *image,
						      const pixman_indexed_t	   *indexed);

/**
 * @brief Gets the data of given image
 * @param [in] image Pixman Image
 * @return Data field of given image
 * @see pixman_image_set_destroy_function
 * @see pixman_image_destroy_data
 */
uint32_t       *pixman_image_get_data                (pixman_image_t               *image);

/**
 * @brief Gets the width of image
 * @param [in] image Pixman Image
 * @return Width of image
 * @see pixman_image_get_height
 */
int		pixman_image_get_width               (pixman_image_t               *image);

/**
 * @brief Gets the height of image
 * @param [in] image Pixman Image
 * @return Height of image
 * @see pixman_image_get_width
 */
int             pixman_image_get_height              (pixman_image_t               *image);

/**
 * @brief Gets the stride of image
 * @param [in] image Pixman Image
 * @return Stride of image
 */
int		pixman_image_get_stride              (pixman_image_t               *image); /* in bytes */

/**
 * @brief Gets the depth of image
 * @param [in] image Pixman Image
 * @return Depth of image
 */
int		pixman_image_get_depth               (pixman_image_t		   *image);

/**
 * @brief Gets the format of image
 * @param [in] image Pixman Image
 * @return Format of image
 */
pixman_format_code_t pixman_image_get_format	     (pixman_image_t		   *image);

/**
 * @brief Fills the image with given color and rectangles
 * @param [in] op Type of Composition
 * @param [in] image Pixman Image
 * @param [in] color Color to be filled
 * @param [in] n_rects Number of rectangles
 * @param [in] rects Rectangles to be filled
 * @return 1 if operation is successful, 0 otherwise
 * @see pixman_image_fill_boxes
 */
pixman_bool_t	pixman_image_fill_rectangles	     (pixman_op_t		    op,
						      pixman_image_t		   *image,
						      const pixman_color_t	   *color,
						      int			    n_rects,
						      const pixman_rectangle16_t   *rects);

/**
 * @brief Fills the image with given color and boxes
 * @param [in] op Type of Composition
 * @param [in] dest Pixman Image
 * @param [in] color Color to be filled
 * @param [in] n_boxes Number of boxes
 * @param [in] boxes boxes to be filled
 * @return 1 if operation is successful, 0 otherwise
 * @see pixman_image_fill_rectangles
 */
pixman_bool_t   pixman_image_fill_boxes              (pixman_op_t                   op,
                                                      pixman_image_t               *dest,
                                                      const pixman_color_t         *color,
                                                      int                           n_boxes,
                                                      const pixman_box32_t         *boxes);

/* Composite */

/**
 * @brief Computes the composited region for given Source, Mask and Destination images
 * @param [in] region 16-bit region
 * @param [in] src_image Source image
 * @param [in] mask_image Mask Image
 * @param [out] dest_image Destination Image
 * @param [in] src_x Source X coordinate
 * @param [in] src_y Source Y coordinate
 * @param [in] mask_x Mask X coordinate
 * @param [in] mask_y Mask Y coordinate
 * @param [in] dest_x Destination X coordinate
 * @param [in] dest_y Destination Y coordinate
 * @param [in] width Width of composited region
 * @param [in] height Height of composited region
 * @return 1 if operation is successful, 0 otherwise
 * @see pixman_image_composite
 */
pixman_bool_t pixman_compute_composite_region (pixman_region16_t *region,
					       pixman_image_t    *src_image,
					       pixman_image_t    *mask_image,
					       pixman_image_t    *dest_image,
					       int16_t            src_x,
					       int16_t            src_y,
					       int16_t            mask_x,
					       int16_t            mask_y,
					       int16_t            dest_x,
					       int16_t            dest_y,
					       uint16_t           width,
					       uint16_t           height);

/**
 * @brief Composes the given Source and Mask images to form a Destination image
 * @param [in] op Type of Composition
 * @param [in] src Source image
 * @param [in] mask Mask Image
 * @param [out] dest Destination Image
 * @param [in] src_x 16-bit Source X coordinate
 * @param [in] src_y 16-bit Source Y coordinate
 * @param [in] mask_x 16-bit Mask X coordinate
 * @param [in] mask_y 16-bit Mask Y coordinate
 * @param [in] dest_x 16-bit Destination X coordinate
 * @param [in] dest_y 16-bit Destination Y coordinate
 * @param [in] width 16-bit Width of composited region
 * @param [in] height 16-bit Height of composited region
 * @see pixman_compute_composite_region
 */
void          pixman_image_composite          (pixman_op_t        op,
					       pixman_image_t    *src,
					       pixman_image_t    *mask,
					       pixman_image_t    *dest,
					       int16_t            src_x,
					       int16_t            src_y,
					       int16_t            mask_x,
					       int16_t            mask_y,
					       int16_t            dest_x,
					       int16_t            dest_y,
					       uint16_t           width,
					       uint16_t           height);

/**
 * @brief Composes the given Source and Mask images to form a Destination image
 * @param [in] op Type of Composition
 * @param [in] src Source image
 * @param [in] mask Mask Image
 * @param [out] dest Destination Image
 * @param [in] src_x 32-bit Source X coordinate
 * @param [in] src_y 32-bit Source Y coordinate
 * @param [in] mask_x 32-bit Mask X coordinate
 * @param [in] mask_y 32-bit Mask Y coordinate
 * @param [in] dest_x 32-bit Destination X coordinate
 * @param [in] dest_y 32-bit Destination Y coordinate
 * @param [in] width 32-bit Width of composited region
 * @param [in] height 32-bit Height of composited region
 * @see pixman_compute_composite_region
 */
void          pixman_image_composite32        (pixman_op_t        op,
					       pixman_image_t    *src,
					       pixman_image_t    *mask,
					       pixman_image_t    *dest,
					       int32_t            src_x,
					       int32_t            src_y,
					       int32_t            mask_x,
					       int32_t            mask_y,
					       int32_t            dest_x,
					       int32_t            dest_y,
					       int32_t            width,
					       int32_t            height);


/* Executive Summary: This function is a no-op that only exists
 * for historical reasons.
 *
 * There used to be a bug in the X server where it would rely on
 * out-of-bounds accesses when it was asked to composite with a
 * window as the source. It would create a pixman image pointing
 * to some bogus position in memory, but then set a clip region
 * to the position where the actual bits were.
 *
 * Due to a bug in old versions of pixman, where it would not clip
 * against the image bounds when a clip region was set, this would
 * actually work. So when the pixman bug was fixed, a workaround was
 * added to allow certain out-of-bound accesses. This function disabled
 * those workarounds.
 *
 * Since 0.21.2, pixman doesn't do these workarounds anymore, so now this
 * function is a no-op.
 */

/**
 * @brief Disables the workarounds that fixed earlier Pixman bugs. This is a no-op function.
 */
void pixman_disable_out_of_bounds_workaround (void);

/*
 * Glyphs
 */

/*! \var typedef struct pixman_glyph_cache_t pixman_glyph_cache_t
	\brief Type definition for #pixman_glyph_cache_t
*/
typedef struct pixman_glyph_cache_t pixman_glyph_cache_t;

/*! \struct pixman_glyph_t
	\brief Type used to represent glyph and its dimensions
*/
typedef struct
{
    int		x, 	/**< X coordinate */
			y;	/**< Y coordinate */
    const void *glyph;	/**< Reference to the glyph*/
} pixman_glyph_t;

/**
 * @brief Creates a blank glyph cache
 * @return Initialized glyph cache
 * @see pixman_glyph_cache_destroy
 * @see pixman_glyph_cache_freeze
 * @see pixman_glyph_cache_thaw
 */
pixman_glyph_cache_t *pixman_glyph_cache_create       (void);

/**
 * @brief Destroys the given glyph cache after clearing its contents
 * @param [in] cache Glyph cache which has to be destroyed
 * @see pixman_glyph_cache_create
 * @see pixman_glyph_cache_freeze
 * @see pixman_glyph_cache_thaw
 */
void                  pixman_glyph_cache_destroy      (pixman_glyph_cache_t *cache);

/**
 * @brief Increases the freeze count of given glyph cache
 * @param [in] cache Glyph cache which has to be frozen
 * @see pixman_glyph_cache_create
 * @see pixman_glyph_cache_destroy
 * @see pixman_glyph_cache_thaw
 */
void                  pixman_glyph_cache_freeze       (pixman_glyph_cache_t *cache);

/**
 * @brief Decreases(Thaws) the freeze count of given glyph cache
 * @param [in] cache Glyph cache which has to be thawed
 * @see pixman_glyph_cache_create
 * @see pixman_glyph_cache_destroy
 * @see pixman_glyph_cache_freeze
 */
void                  pixman_glyph_cache_thaw         (pixman_glyph_cache_t *cache);

/**
 * @brief Gets the glyph associated with the Font key and Glyph key lookup-pair
 * @param [in] cache Glyph cache
 * @param [in] font_key Font key
 * @param [in] glyph_key Glyph key
 * @return Glyph indexed by the lookup-pair
 * @see pixman_glyph_cache_insert
 * @see pixman_glyph_cache_remove
 */
const void *          pixman_glyph_cache_lookup       (pixman_glyph_cache_t *cache,
						       void                 *font_key,
						       void                 *glyph_key);

/**
 * @brief Inserts the glyph into the glyph cache
 * @param [in] cache Glyph cache
 * @param [in] font_key Font key
 * @param [in] glyph_key Glyph key
 * @param [in] origin_x X coordinate
 * @param [in] origin_y Y coordinate
 * @param [in] glyph_image Image of the glyph
 * @return Glyph inserted in the cache
 * @see pixman_glyph_cache_lookup
 * @see pixman_glyph_cache_remove
 */
const void *          pixman_glyph_cache_insert       (pixman_glyph_cache_t *cache,
						       void                 *font_key,
						       void                 *glyph_key,
						       int		     origin_x,
						       int                   origin_y,
						       pixman_image_t       *glyph_image);

/**
 * @brief Removes the glyph associated with the Font key and Glyph key lookup-pair
 * @param [in] cache Glyph cache
 * @param [in] font_key Font key
 * @param [in] glyph_key Glyph key
 * @see pixman_glyph_cache_insert
 * @see pixman_glyph_cache_lookup
 */
void                  pixman_glyph_cache_remove       (pixman_glyph_cache_t *cache,
						       void                 *font_key,
						       void                 *glyph_key);

/**
 * @brief Gets the extents when all given glyphs are composed
 * @param [in] cache Glyph cache
 * @param [in] n_glyphs Number of glyphs
 * @param [in] glyphs Reference to glyphs
 * @param [out] extents Reference to the extents of all glyphs
 */
void                  pixman_glyph_get_extents        (pixman_glyph_cache_t *cache,
						       int                   n_glyphs,
						       pixman_glyph_t       *glyphs,
						       pixman_box32_t       *extents);

/**
 * @brief Returns a format that is suitable for use as a mask for the set of glyphs in question
 * @param [in] cache Glyph cache
 * @param [in] n_glyphs Number of glyphs
 * @param [in] glyphs Reference to glyphs
 * @return Color format for the glyph mask
 */
pixman_format_code_t  pixman_glyph_get_mask_format    (pixman_glyph_cache_t *cache,
						       int		     n_glyphs,
						       const pixman_glyph_t *glyphs);

/**
 * @brief Composes Src image with all the glyphs by using a Mask on a given Dst image
 * @param [in] op Type of composition
 * @param [in] src Source image
 * @param [out] dest Destination image
 * @param [in] mask_format Color format
 * @param [in] src_x X coordinate of Src image
 * @param [in] src_y Y coordinate of Src image
 * @param [in] mask_x X coordinate of Masked image
 * @param [in] mask_y Y coordinate of Masked image
 * @param [in] dest_x X coordinate of Dst image
 * @param [in] dest_y Y coordinate of Dst image
 * @param [in] width Width of Dst image
 * @param [in] height Height of Dst image
 * @param [in] cache Glyph cache
 * @param [in] n_glyphs Number of glyphs
 * @param [in] glyphs Reference to glyphs
 * @see pixman_composite_glyphs_no_mask
 */
void                  pixman_composite_glyphs         (pixman_op_t           op,
						       pixman_image_t       *src,
						       pixman_image_t       *dest,
						       pixman_format_code_t  mask_format,
						       int32_t               src_x,
						       int32_t               src_y,
						       int32_t		     mask_x,
						       int32_t		     mask_y,
						       int32_t               dest_x,
						       int32_t               dest_y,
						       int32_t		     width,
						       int32_t		     height,
						       pixman_glyph_cache_t *cache,
						       int		     n_glyphs,
						       const pixman_glyph_t *glyphs);

/**
 * @brief Composes Src image with all the glyphs without using a Mask on a given Dst image.
 * @param [in] op Type of composition
 * @param [in] src Source image
 * @param [out] dest Destination image
 * @param [in] src_x X coordinate of Src image
 * @param [in] src_y Y coordinate of Src image
 * @param [in] dest_x X coordinate of Dst image
 * @param [in] dest_y Y coordinate of Dst image
 * @param [in] cache Glyph cache
 * @param [in] n_glyphs Number of glyphs
 * @param [in] glyphs Reference to glyphs
 * @see pixman_composite_glyphs
 */
void                  pixman_composite_glyphs_no_mask (pixman_op_t           op,
						       pixman_image_t       *src,
						       pixman_image_t       *dest,
						       int32_t               src_x,
						       int32_t               src_y,
						       int32_t               dest_x,
						       int32_t               dest_y,
						       pixman_glyph_cache_t *cache,
						       int		     n_glyphs,
						       const pixman_glyph_t *glyphs);

/*
 * Trapezoids
 */
 /*! \var typedef struct pixman_edge pixman_edge_t
	\brief Type definition for #pixman_edge
*/
typedef struct pixman_edge pixman_edge_t;

 /*! \var typedef struct pixman_trapezoid pixman_trapezoid_t
	\brief Type definition for #pixman_trapezoid
*/
typedef struct pixman_trapezoid pixman_trapezoid_t;

 /*! \var typedef struct pixman_trap pixman_trap_t
	\brief Type definition for #pixman_trap
*/
typedef struct pixman_trap pixman_trap_t;

 /*! \var typedef struct pixman_span_fix pixman_span_fix_t
	\brief Type definition for #pixman_span_fix
*/
typedef struct pixman_span_fix pixman_span_fix_t;

 /*! \var typedef struct pixman_triangle pixman_triangle_t
	\brief Type definition for #pixman_triangle
*/
typedef struct pixman_triangle pixman_triangle_t;

/*
 * An edge structure.  This represents a single polygon edge
 * and can be quickly stepped across small or large gaps in the
 * sample grid
 */

/*! \struct pixman_edge
	\brief Type used to represent an edge
*/
struct pixman_edge
{
    pixman_fixed_t	x;	/**<X coordinate of the top point*/
    pixman_fixed_t	e;	/**<Length of the edge*/
    pixman_fixed_t	stepx;	/**<Steps in X direction*/
    pixman_fixed_t	signdx;		/**<Positive/Negative slope of edge*/
    pixman_fixed_t	dy;		/**<Diff of Y coordinates*/
    pixman_fixed_t	dx;		/**<Diff of X coordinates*/

    pixman_fixed_t	stepx_small;		/**<Small steps in X direction*/
    pixman_fixed_t	stepx_big;		/**<Big steps in X direction*/
    pixman_fixed_t	dx_small;		/**<Diff of X coordinates during small steps*/
    pixman_fixed_t	dx_big;		/**<Diff of Y coordinates during big steps*/
};


/*! \struct pixman_trapezoid
	\brief Type used to represent a trapezoid
*/
struct pixman_trapezoid
{
    pixman_fixed_t	top, 		/**<Top coordinate*/
				bottom;		/**<Bottom coordinate*/
    pixman_line_fixed_t	left, 	/**<Left coordinate*/
				right;		/**<Right coordinate*/
};


/*! \struct pixman_triangle
	\brief Type used to represent a triangle
*/
struct pixman_triangle
{
    pixman_point_fixed_t p1,		/**<Point of a triangle*/
					p2, 		/**<Point of a triangle*/
					p3;		/**<Point of a triangle*/
};

/* whether 't' is a well defined not obviously empty trapezoid */
/*! \def pixman_trapezoid_valid
	\brief Validates the given trapezoid
*/
#define pixman_trapezoid_valid(t)				   \
    ((t)->left.p1.y != (t)->left.p2.y &&			   \
     (t)->right.p1.y != (t)->right.p2.y &&			   \
     (int) ((t)->bottom - (t)->top) > 0)


/*! \struct pixman_span_fix
	\brief Type used to represent a geometric span
*/
struct pixman_span_fix
{
    pixman_fixed_t	l, 		/**<Left coordinate of a span*/
		r, /**<Right coordinate of a span*/
		y;/**<Y coordinate of a span*/
};


/*! \struct pixman_trap
	\brief Type used to represent a geometric trap
*/
struct pixman_trap
{
    pixman_span_fix_t	top, /**<Top span of the trap*/
		bot;/**<Bottom span of the trap*/
};


/**
 * @brief Gives the smallest value greater than or equal to y in a given row
 * @param [in] y A fixed integer
 * @param [in] bpp BPP
 * @return Ceil value of y
 * @see pixman_sample_floor_y
 */
pixman_fixed_t pixman_sample_ceil_y        (pixman_fixed_t             y,
					    int                        bpp);

/**
 * @brief Gives the largest value lesser than y in a given row
 * @param [in] y A fixed integer
 * @param [in] bpp BPP
 * @return Floor value of y
 * @see pixman_sample_ceil_y
 */
pixman_fixed_t pixman_sample_floor_y       (pixman_fixed_t             y,
					    int                        bpp);

/**
 * @brief Steps an edge by the given amount (including negative values)
 * @param [in] e Edge
 * @param [in] n Steps to add for the edge
 * @see pixman_edge_init
 * @see pixman_line_fixed_edge_init
 * @see pixman_rasterize_edges
 */
void           pixman_edge_step            (pixman_edge_t             *e,
					    int                        n);

/**
 * @brief Initializes an edge with given points
 * @param [in] e Edge
 * @param [in] bpp BPP
 * @param [in] y_start Starting value of Y
 * @param [in] x_top X coordinate of the top point
 * @param [in] y_top Y coordinate of the top point
 * @param [in] x_bot X coordinate of the bottom point
 * @param [in] y_bot Y coordinate of the bottom point
 * @see pixman_edge_step
 * @see pixman_line_fixed_edge_init
 * @see pixman_rasterize_edges
 */
void           pixman_edge_init            (pixman_edge_t             *e,
					    int                        bpp,
					    pixman_fixed_t             y_start,
					    pixman_fixed_t             x_top,
					    pixman_fixed_t             y_top,
					    pixman_fixed_t             x_bot,
					    pixman_fixed_t             y_bot);

/**
 * @brief Initializes an edge with given line and offset
 * @param [in] e Edge
 * @param [in] bpp BPP
 * @param [in] y Starting value of Y
 * @param [in] line Line
 * @param [in] x_off X offset from the coordinate axis
 * @param [in] y_off Y offset  from the coordinate axis
 * @see pixman_edge_step
 * @see pixman_edge_init
 * @see pixman_rasterize_edges
 */
void           pixman_line_fixed_edge_init (pixman_edge_t             *e,
					    int                        bpp,
					    pixman_fixed_t             y,
					    const pixman_line_fixed_t *line,
					    int                        x_off,
					    int                        y_off);

/**
 * @brief Rasterizes the given edge and writes it to the given image
 * @param [in] image Image to store the rasterized edge
 * @param [in] l Left edge
 * @param [in] r Right edge
 * @param [in] t Y coordinate of the top point
 * @param [in] b Y coordinate of the bottom point
 * @see pixman_edge_step
 * @see pixman_edge_init
 * @see pixman_line_fixed_edge_init
 */
void           pixman_rasterize_edges      (pixman_image_t            *image,
					    pixman_edge_t             *l,
					    pixman_edge_t             *r,
					    pixman_fixed_t             t,
					    pixman_fixed_t             b);

/**
 * @brief Adds the given traps into an image
 * @param [in] image Image to store the added traps
 * @param [in] x_off X offset from the coordinate axis
 * @param [in] y_off Y offset  from the coordinate axis
 * @param [in] ntrap Number of traps
 * @param [in] traps Reference to all the traps
 */
void           pixman_add_traps            (pixman_image_t            *image,
					    int16_t                    x_off,
					    int16_t                    y_off,
					    int                        ntrap,
					    const pixman_trap_t       *traps);

/**
 * @brief Adds the given trapezoids into an image
 * @param [in] image Image to store the added trapezoids
 * @param [in] x_off X offset from the coordinate axis
 * @param [in] y_off Y offset  from the coordinate axis
 * @param [in] ntraps Number of trapezoids
 * @param [in] traps Reference to all the trapezoids
 */
void           pixman_add_trapezoids       (pixman_image_t            *image,
					    int16_t                    x_off,
					    int                        y_off,
					    int                        ntraps,
					    const pixman_trapezoid_t  *traps);

/**
 * @brief Rasterizes the given trapezoid into an image
 * @param [in] image Image to store the added trapezoids
 * @param [in] trap Reference to the trapezoid
 * @param [in] x_off X offset from the coordinate axis
 * @param [in] y_off Y offset  from the coordinate axis
 */
void           pixman_rasterize_trapezoid  (pixman_image_t            *image,
					    const pixman_trapezoid_t  *trap,
					    int                        x_off,
					    int                        y_off);

/**
 * @brief A Mask is formed by the given traps and it is composed using Src image on Dst image
 * @param [in] op Type of composition
 * @param [in] src Source image
 * @param [out] dst Destination image
 * @param [in] mask_format Color format
 * @param [in] x_src X coordinate of Src image
 * @param [in] y_src Y coordinate of Src image
 * @param [in] x_dst X coordinate of Dst image
 * @param [in] y_dst Y coordinate of Dst image
 * @param [in] n_traps Number of traps
 * @param [in] traps Reference to the traps to compose
 */
void          pixman_composite_trapezoids (pixman_op_t		       op,
					   pixman_image_t *	       src,
					   pixman_image_t *	       dst,
					   pixman_format_code_t	       mask_format,
					   int			       x_src,
					   int			       y_src,
					   int			       x_dst,
					   int			       y_dst,
					   int			       n_traps,
					   const pixman_trap_t       *traps);

/**
 * @brief A Mask is formed by the given triangles and it is composed using Src image on Dst image
 * @param [in] op Type of composition
 * @param [in] src Source image
 * @param [out] dst Destination image
 * @param [in] mask_format Color format
 * @param [in] x_src X coordinate of Src image
 * @param [in] y_src Y coordinate of Src image
 * @param [in] x_dst X coordinate of Dst image
 * @param [in] y_dst Y coordinate of Dst image
 * @param [in] n_tris Number of triangles
 * @param [in] tris Reference to the triangles to compose
 */
void          pixman_composite_triangles (pixman_op_t		       op,
					  pixman_image_t *	       src,
					  pixman_image_t *	       dst,
					  pixman_format_code_t	       mask_format,
					  int			       x_src,
					  int			       y_src,
					  int			       x_dst,
					  int			       y_dst,
					  int			       n_tris,
					  const pixman_triangle_t *    tris);

/**
 * @brief Adds the given triangles into an image
 * @param [in] image Image to store the added trapezoids
 * @param [in] x_off X offset from the coordinate axis
 * @param [in] y_off Y offset  from the coordinate axis
 * @param [in] n_tris Number of triangles
 * @param [in] tris Reference to all the triangles
 */
void	      pixman_add_triangles       (pixman_image_t              *image,
					  int32_t	               x_off,
					  int32_t	               y_off,
					  int	                       n_tris,
					  const pixman_triangle_t     *tris);

PIXMAN_END_DECLS
/** @}*/
#endif /* PIXMAN_H__ */
