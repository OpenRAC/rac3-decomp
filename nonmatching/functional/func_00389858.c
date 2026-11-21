/* functional: high. draft from nonmatching/ checked against PAL asm (constants 1024.0, offsets, D_ names, arg order all agree); only scheduling differs (67 diff words). */
#include "common.h"
#include "vu0.h"
extern f32 D_222400[];
extern f32 D_225B20[];
extern s32 D_1D4BC0[];
extern s32 D_1D4BC4[];
void func_00389858(f32 *point, f32 *x, f32 *y) {
    f32 v[4] __attribute__((aligned(16)));
    vec_sub_ba(v,point,D_222400);
    func_0038D200(v,v,1024.0f);
    v[3]=1.0f;
    func_0038D408(v,v,D_222400-64);
    func_0038D200(v,v,D_225B20[0]/v[3]);
    *x=v[0]+(f32)(D_1D4BC0[0]>>1);
    *x/=(f32)D_1D4BC0[0];
    *y=v[1]+(f32)(D_1D4BC4[0]>>1);
    *y/=(f32)D_1D4BC4[0];
}
