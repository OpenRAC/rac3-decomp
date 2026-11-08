#include "common.h"

/* localdecomp:start func_L39_006096D0 */
typedef struct { s32 f0; s32 f4; s32 f8; u8 pC[0xC]; s32 f18; u8 p1C[0x24]; s32 f40; u8 p44[4]; long f48; s32 f50; s32 f54; } Type1;
typedef struct { s32 w0; s32 w4; s32 w8; s32 pad[5]; } Type2;
extern s32 func_00126260();
extern s32 func_003B16F8();

/* from rac4-decomp's func_004F0CF0, renamed */
s32 func_L39_006096D0(Type1 *o, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
{  Type2 *var1;
  Type2 st;
  o->f0 = a1;
  o->f8 = a3;
  o->f50 = a4;
  o->f54 = a5;
  st.w8 = 1;
  o->f4 = (a2 & 0xFFFFFFF) | 0x20000000;
  st.w4 = 1;
  var1 = &st;
  o->f18 = a3 << 11;
  o->f40 = func_00126260(var1);
  ((s32 (*)(void *))func_003B16F8)(o);
  o->f48 = 0;
  return 1;
}
/* localdecomp:end func_L39_006096D0 */
