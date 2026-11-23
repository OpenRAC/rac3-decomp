/* functional: high. VU0 vsub via inline asm per rules. Scheduling only after alignment. */
#include "common.h"
/* localdecomp:start func_L01_004E96E8 */
extern u8 D_001A4C60[];
extern u8 D_001A4C20[];
extern S_4E56A8q D_L01_001E2A40;
f32 func_L01_004E96E8(S_4E56A8m *moby, Vec4 *forward, s32 *out, void *camera_matrix, f32 range, f32 yaw_limit, f32 pitch_limit) {
 extern f32 func_0038CF00(S_4E56A8vec *, S_4E56A8vec *);
 extern void func_0038D028(Vec4 *, void *, void *);
 extern f32 func_0038D160(f32, f32);
 extern f32 func_0038DBA0(f32, f32);
 extern f32 func_0038CED8(void *);
 extern s32 func_003C4B50(S_4E56A8m *);
 Vec4 position, direction, facing, camera_direction;
 u8 *hero;
 void *matrix;
 f32 distance, angle, facing_angle, yaw, pitch, limit, result;
 *out = 0;
 position.q = *(s128 *)D_001A4C60;
 hero = D_001A4C60 - 0x80;
 if (*(s32 *)(hero + 0x25C4) == 20 && *(f32 *)(hero + 0x338) > 0.0f) {
  position.q = *(s128 *)(hero + 0x2F0);
 }
 distance = func_0038CF00((S_4E56A8vec *)&position, &moby->x10);
 if (range < distance) *out = 1;
 __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
 : "=m"(direction) : "m"(moby->x10), "m"(position) : "vf1", "vf2");
 matrix = D_001A4C20;
 func_0038D028(&direction, &direction, matrix);
 facing.q = forward->q;
 func_0038D028(&facing, &facing, matrix);
 angle = func_0038D160(direction.f[0], direction.f[1]);
 facing_angle = func_0038D160(facing.f[0], facing.f[1]);
 yaw = func_0038DBA0(angle, facing_angle);
 limit = yaw;
 pitch = func_0038D160(func_0038CED8(&direction), direction.f[2]);
 if (*(s32 *)((u8 *)matrix + 0x2584) == 1 || *(s32 *)((u8 *)matrix + 0x2584) == 29) {
  __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
 : "=m"(camera_direction) : "m"(moby->x10), "m"(D_L01_001E2A40.x0) : "vf1", "vf2");
  func_0038D028(&camera_direction, &camera_direction, camera_matrix);
  angle = func_0038D160(camera_direction.f[0], camera_direction.f[1]);
  pitch = func_0038D160(func_0038CED8(&camera_direction), camera_direction.f[2]);
  limit = pitch;
  yaw = angle + pitch;
  if (pitch < angle) limit = angle;
 }
 if (0.0f < yaw_limit && yaw_limit < limit) *out = 1;
 if (0.0f < pitch_limit && pitch_limit < pitch) *out = 1;
 result = distance + yaw * distance;
 if (func_003C4B50(moby)) result += range * 0.8f;
 return result;
}
/* localdecomp:end func_L01_004E96E8 */
