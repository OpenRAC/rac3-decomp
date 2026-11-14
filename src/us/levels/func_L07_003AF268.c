#include "common.h"

/* NTSC-U counterpart of func_L07_003B0B08 (src/levels/07_annihilation_nation/L07_003AF398.c) */
/* localdecomp:start func_L07_003AF268 */
extern void func_L07_003AF458(void *);
extern void func_L01_004A6D70(s32, void *);
extern void func_L07_003AF740(void *);
extern void func_L07_003AF680(void *);
extern void func_L07_003AF568(void *, s32);
extern s32 func_L07_003AFA20(void *);
extern void func_L07_003AFB30(void *);
extern f32 func_003BE6A8(f32, f32, f32);
extern void func_003C26C8(void *);

void func_L07_003AF268(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *vars;

    func_L07_003AF458(obj);
    vars = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 1:
        break;
    case 3:
        if (obj[0x60] & 2) {
            func_L01_004A6D70(0, obj);
            func_L07_003AF740(obj);
            func_L07_003AF568(obj, 4);
        } else {
            func_L07_003AF680(obj);
        }
        break;
    case 4:
        *(f32 *)(vars + 0x48) = *(f32 *)(vars + 0x48) + 0.01f;
        if (*(f32 *)(vars + 0x48) >= 1.0f) {
            *(f32 *)(vars + 0x48) = 1.0f;
            func_L01_004A6D70(1, obj);
            func_L07_003AF568(obj, 2);
        }
        *(f32 *)(*(u8 **)(vars + 0x44) + 0xF0) = func_003BE6A8(0.0f, -1.5707964f, *(f32 *)(vars + 0x48));
        func_003C26C8(*(u8 **)(vars + 0x44));
        break;
    case 2:
        if (func_L07_003AFA20(obj) != 0) {
            func_L07_003AF568(obj, 5);
        }
        break;
    case 5:
        if (func_L07_003AFA20(obj) == 0) {
            func_L07_003AF568(obj, 4);
            break;
        }
        *(f32 *)(vars + 0x48) = *(f32 *)(vars + 0x48) - 0.01f;
        if (*(f32 *)(vars + 0x48) <= 0.0f) {
            *(f32 *)(vars + 0x48) = 0.0f;
            func_L01_004A6D70(1, obj);
            func_L07_003AF568(obj, 6);
        }
        *(f32 *)(*(u8 **)(vars + 0x44) + 0xF0) = func_003BE6A8(0.0f, -1.5707964f, *(f32 *)(vars + 0x48));
        func_003C26C8(*(u8 **)(vars + 0x44));
        break;
    case 6:
        if (obj[0x60] & 2) {
            func_L01_004A6D70(0, obj);
            func_L07_003AFB30(obj);
            func_L07_003AF568(obj, 1);
        } else {
            func_L07_003AF680(obj);
        }
        break;
    }
}
/* localdecomp:end func_L07_003AF268 */
