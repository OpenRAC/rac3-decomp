/* functional: high. Spawns a 0x6D effect object at pos with velocity vel (quad copies), random alpha byte (0..255), life (rand(5,50)*5+2)/6 ticks, size f*210000*2.5, a random 0x40..0x80 stored at +0x30 and baked into the top byte of the colour word (func_0038DBD8(0x103080, 0, rand 0..0.5) | rand<<24); same order of calls as retail. */
/* localdecomp:start func_L39_005D3B70 */
typedef struct { f32 x, y, z, w; } L39V4_5D3B70;

extern u8 *D_L39_002969CC;
extern void *func_003CD108(s32);
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_005B43C8(s32, s32);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);

u8 *func_L39_005D3B70(void *pos, void *vel, s32 b, f32 f) {
    u8 *obj;
    u8 *e;
    s32 r;

    obj = func_003CD108(0x6D);
    if (obj != 0) {
        *(L39V4_5D3B70 *)(obj + 0x10) = *(L39V4_5D3B70 *)pos;
        obj[3] = b;
        obj[1] = 0;
        e = obj + 0x20;
        obj[9] = 0x44;
        obj[8] = func_L39_005B4398(0xFF);
        r = func_L39_005B43C8(5, 0x32);
        *(f32 *)(obj + 0xC) = f * 210000.0f * 2.5f;
        *(s16 *)(obj + 0xA) = (r * 5 + 2) / 6;
        *(L39V4_5D3B70 *)(obj + 0x20) = *(L39V4_5D3B70 *)vel;
        *(s32 *)(e + 0x10) = func_L39_005B43C8(0x40, 0x80);
        obj[2] = *D_L39_002969CC;
        *(s32 *)(obj + 4) = func_0038DBD8(0x103080, 0, func_L39_005B4410(0.0f, 0.5f)) | (*(s32 *)(e + 0x10) << 24);
    }
    return obj;
}
/* localdecomp:end func_L39_005D3B70 */
