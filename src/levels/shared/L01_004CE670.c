#include "common.h"

/* localdecomp:start func_L01_004CE670 */
extern s32 func_00381FF0(s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern void func_L01_004CDB70(u8 *, s32, s32, f32, f32);

/* prints a localised format string into a label's text buffer (label + 0x88) */
static __inline__ void setTextf_004CE670(u8 *label, s32 id, s32 arg) {
    func_0011B2E8((char *)label + 0x88, (char *)func_00381FF0(id), arg);
}

void func_L01_004CE670(u8 *p, s32 i, s32 id, s32 arg, s32 color) {
    if (color == -1) {
        color = 0x64;
    }
    setTextf_004CE670(p + (i * 0x230 + 0x4610), id, arg);
    func_L01_004CDB70(p + (i * 0x230 + 0x4610), 1, color, 255.0f, 135.0f);
}
/* localdecomp:end func_L01_004CE670 */

/* localdecomp:start func_L01_004CE720 */
s32 func_L01_004CE720(u8 *a0, s32 a1) {
    return 0.0f < **(f32 **)(a0 + a1 * 0x230 + 0x4614);
}
/* localdecomp:end func_L01_004CE720 */

/* localdecomp:start func_L01_004CE758 */
extern char *func_0011BB58(char *, char *, s32);
extern void func_L01_004CDC38(void *, s32, s32, f32, f32);

/* copies a string into a label's text buffer (label + 0x88, 0xFE bytes) */
static __inline__ void setText_004CE758(u8 *label, char *src) {
    func_0011BB58((char *)label + 0x88, src, 0xFE);
}

void func_L01_004CE758(u8 *p, s32 i, char *text, s32 color) {
    if (color == -1) {
        color = 0x96;
    }
    setText_004CE758(p + (i * 0x230 + 0x4610), text);
    func_L01_004CDC38(p + (i * 0x230 + 0x4610), 1, color, 255.0f, 135.0f);
}
/* localdecomp:end func_L01_004CE758 */

/* localdecomp:start func_L01_004CE7E8 */
void func_L01_004CE7E8(void) {

}
/* localdecomp:end func_L01_004CE7E8 */
