#include "common.h"

/* localdecomp:start func_L12_00449F60 */
typedef struct Type1 { f32 f0; f32 f4; f32 f8; f32 fC; f32 f10; f32 f14; f32 f18; f32 f1C; f32 f20; f32 f24; f32 f28; f32 f2C; } Type1;

/* from rac4-decomp's func_00476320, renamed */
void func_L12_00449F60(Type1 *arg0, Type1 *arg1) {
    arg0->f0 = (f32) ((arg1->f28 * arg1->f14) - (arg1->f18 * arg1->f24));
    arg0->f4 = (f32) ((arg1->f8 * arg1->f24) - (arg1->f28 * arg1->f4));
    arg0->f8 = (f32) ((arg1->f18 * arg1->f4) - (arg1->f8 * arg1->f14));
    arg0->fC = 0.0f;
    arg0->f10 = (f32) ((arg1->f18 * arg1->f20) - (arg1->f10 * arg1->f28));
    arg0->f14 = (f32) ((arg1->f28 * arg1->f0) - (arg1->f8 * arg1->f20));
    arg0->f18 = (f32) ((arg1->f10 * arg1->f8) - (arg1->f18 * arg1->f0));
    arg0->f1C = 0.0f;
    arg0->f20 = (f32) ((arg1->f10 * arg1->f24) - (arg1->f20 * arg1->f14));
    arg0->f24 = (f32) ((arg1->f20 * arg1->f4) - (arg1->f0 * arg1->f24));
    arg0->f28 = (f32) ((arg1->f0 * arg1->f14) - (arg1->f10 * arg1->f4));
    arg0->f2C = 0.0f;
}
/* localdecomp:end func_L12_00449F60 */
