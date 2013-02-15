#include <tet_api.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pixman.h>

static void startup(void);
static void cleanup(void);

void (*tet_startup)(void) = startup;
void (*tet_cleanup)(void) = cleanup;

static void utc_pixman_a1_trap(void);

struct tet_testlist tet_testlist[] = {
	{ utc_pixman_a1_trap, 1 },
	{ NULL, 0 },
};

static void startup(void)
{
	/* start of TC */
}

static void cleanup(void)
{
	/* end of TC */
}

static void utc_pixman_a1_trap(void)
{

#define WIDTH 20
#define HEIGHT 20

    pixman_image_t *src_img;
    pixman_image_t *mask_img;
    pixman_image_t *dest_img;
    pixman_trap_t trap;
    pixman_color_t red = { 0xffff, 0x0000, 0x0000, 0xffff };
    uint32_t *bits = malloc (WIDTH * HEIGHT * 4);
    uint32_t *mbits = malloc (WIDTH * HEIGHT);

    memset (mbits, 0, WIDTH * HEIGHT);
    memset (bits, 0xff, WIDTH * HEIGHT * 4);

    trap.top.l = pixman_double_to_fixed (0.5);
    trap.top.r = pixman_double_to_fixed (1.5);
    trap.top.y = pixman_double_to_fixed (0.5);

    trap.bot.l = pixman_double_to_fixed (0.5);
    trap.bot.r = pixman_double_to_fixed (1.5);
    trap.bot.y = pixman_double_to_fixed (1.5);

    mask_img = pixman_image_create_bits (
	PIXMAN_a1, WIDTH, HEIGHT, mbits, WIDTH);
    src_img = pixman_image_create_solid_fill (&red);
    dest_img = pixman_image_create_bits (
	PIXMAN_a8r8g8b8, WIDTH, HEIGHT, bits, WIDTH * 4);

    pixman_add_traps (mask_img, 0, 0, 1, &trap);

    pixman_image_composite (PIXMAN_OP_OVER,
			    src_img, mask_img, dest_img,
			    0, 0, 0, 0, 0, 0, WIDTH, HEIGHT);

    if (bits[0] != 0xffff0000)
        dts_fail("utc_pixman_a1_trap");
    if (bits[1] != 0xffffffff)
        dts_fail("utc_pixman_a1_trap");
    if (bits[1 * WIDTH + 0] != 0xffffffff)
        dts_fail("utc_pixman_a1_trap");
    if (bits[1 * WIDTH + 1] != 0xffffffff)
        dts_fail("utc_pixman_a1_trap");

    dts_pass("utc_pixman_a1_trap");
}
