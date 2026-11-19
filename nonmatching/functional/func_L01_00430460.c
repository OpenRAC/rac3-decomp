/* functional: high. Rewritten from the PAL asm; same bounds, clamps, loop order and early returns. Register allocation differs only. */
typedef struct Map_430460 {
    u8 pad00[0xC];
    u8 *bitmap;
    u8 pad10[0x18];
    s32 active;
    u8 pad2c[0x364];
    u8 mask[32][4];
} Map_430460;
extern s32 D_001D545C;
extern s32 func_L01_004308B0(s32);
extern void func_L01_004316B0(float, float, float *, float *, s32, s32);

s32 func_L01_00430460(float *position, s32 radius) {
    float px, py;
    s32 x, y, minX, minY, maxX, maxY, row, col, dx, dy, bit;
    u8 *cell;
    Map_430460 *m = (Map_430460 *)&D_L01_001F3FA0;
    if (m->active == 0) return 0;
    func_L01_004316B0(position[0], position[1], &px, &py, D_001D545C, -1);
    x = (s32)(px * 512.0f) + 1;
    y = (s32)(py * 512.0f) + 1;
    if (x < 0 || y < 0 || x >= 512 || y >= 512) return 0;
    minX = x - radius; minY = y - radius; maxX = x + radius; maxY = y + radius;
    if (minX < 0) minX = 0;
    if (minY < 0) minY = 0;
    if (maxX >= 512) maxX = 511;
    if (maxY >= 512) maxY = 511;
    func_L01_004308B0((x >> 5) + (y >> 5) * 16);
    for (row = minY; row < maxY; row++) {
        dy = row - y + 16;
        for (col = minX; col < maxX; col++) {
            cell = m->bitmap + row * 64 + col / 8;
            if (*cell == 0) return 1;
            bit = 1 << (col & 7);
            if (!(*cell & bit)) return 1;
            dx = col - x + 16;
            if ((m->mask[0][dx / 8 + dy * 4] >> (dx % 8)) & 1) return 1;
        }
    }
    return 0;
}
