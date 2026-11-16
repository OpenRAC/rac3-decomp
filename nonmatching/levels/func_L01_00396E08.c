/* PAL near miss (Codex wave 6): near miss: 0 words differ with the file's flags.
 * Worker's note: 33/34 places MATCH; level08 one jal diff +0xC8: catalogue callee func_L01_003970C8 resolves 0x0038A6C8 but retail calls duplicate func_L08_0038F660; requires placement/callee map correction. Logs build/codex/w307/func_L01_00396E08.all.log and .level08.log; ...
 */
#include "common.h"
/* localdecomp:start func_L01_00396E08 */
typedef struct {
 u8 pad0[0x10]; Vec4 vector;
 u8 pad20[0x40-0x20]; Vec4 vector40;
 u8 pad50[0x5C-0x50]; s32 timer;
 u8 pad60[0x6C-0x60]; s32 disabled;
} Data_00396E08;
typedef struct {
 u8 pad0[0x10]; Vec4 position;
 u8 state; u8 pad21[0x2C-0x21]; f32 scale;
 u8 pad30[0x68-0x30]; Data_00396E08 *data;
} Object_00396E08;
void func_L01_00396E08(Object_00396E08 *object) {
 extern void func_L01_003973F8(Vec4 *, Vec4 *, f32, u32, s32, f32, f32);
 extern s32 func_00382498(s32, s32);
 extern f32 func_00382538(void);
 extern void func_L01_003970C8(Vec4 *, u32, f32, s32, s32, s32, f32, f32);
 extern void func_L01_00397278(Vec4 *, u32, s32, f32, f32, s32, s32, Vec4 *);
 Data_00396E08 *data = object->data;
 Vec4 position;
 f32 scale;
 s32 number;
 f32 random;
 Vec4 *position1;
 Vec4 *position2;
 f32 zero;
 switch (object->state) {
 case 1:
  position = object->position;
  func_L01_003973F8(&position, &data->vector, 0.0f, 0x103080, 3, 1.0f, 0.25f);
  position1 = &object->position;
  scale = object->scale * 80.0f;
  number = func_00382498(79, 111);
  random = func_00382538();
  func_L01_003970C8(position1, 0x103080, scale, number, 11, 2, random, -1.0f);
  break;
 case 2:
  data->timer--;
  if (data->timer <= 0) data->timer = 0;
  position = object->position;
  zero = 0.0f;
  func_L01_003973F8(&position, &data->vector, zero, 0x103080, 3, 0.85f, 0.25f);
  if (data->disabled == 0) {
   f32 factor;
   f32 object_scale = object->scale;
   position2 = &object->position;
   factor = 45.0f;
   func_L01_00397278(position2, 0x103080, data->timer, object_scale * factor, zero, 11, 2, &data->vector40);
   func_L01_00397278(position2, 0x3F3F3F, data->timer, object->scale * factor * 0.75f, zero, 11, 2, &data->vector40);
  }
  break;
 }
}
/* localdecomp:end func_L01_00396E08 */
