/* functional: high. decls fixed to the file's arrays; loop strength-reduction differences only */
#include "common.h"
/* localdecomp:start func_L01_004C67A0 */
#include "vu0.h"
extern s32 D_001DAE80_sda, D_001DAE88_sda;
__asm__(".extern D_001DAE80_sda, 4");
__asm__(".extern D_001DAE88_sda, 4");
typedef struct { f32 h[16][16]; f32 tail[112]; } Buffer_004C67A0;
typedef struct { f32 x,y; u8 pad8[4]; u8 neighbors[8]; u8 pad14[60]; Buffer_004C67A0 b[3]; } Tile_004C67A0;
void func_L01_004C67A0(Tile_004C67A0 *tiles, s32 count, s32 add, f32 x, f32 y, f32 radius, f32 strength) {
    Tile_004C67A0 *tile = tiles;
    s32 buffer = D_001DAE80_sda, other = D_001DAE88_sda;
    s32 k;
    for (k = 0; k < count; k++, tile++) {
        f32 oy = tile->y + D_L01_001DAEAC[0];
        f32 cy = (y - oy) / D_L01_001DAEB4[0];
        f32 cx = (x - (tile->x + D_L01_001DAEA8[0])) / D_L01_001DAEB0[0];
        s32 ymin = (s32)(cy - radius), ymax = (s32)(cy + radius);
        s32 xmax = (s32)(cx + radius), xmin = (s32)(cx - radius);
        s32 row, col;
        if (ymin < 0) ymin = 0;
        if (ymax > 15) ymax = 15;
        if (xmax > 15) xmax = 15;
        if (xmin < 0) xmin = 0;
        oy += D_L01_001DAEB4[0] * ymin;
        for (row = ymin; row <= ymax; row++, oy += D_L01_001DAEB4[0]) {
            f32 ox = tile->x + D_L01_001DAEA8[0] + D_L01_001DAEB0[0] * xmin;
            for (col = xmin; col <= xmax; col++, ox += D_L01_001DAEB0[0]) {
                f32 d = (x - ox) * (x - ox) + (y - oy) * (y - oy);
                f32 v = strength;
                f32 (*grid)[16] = tile->b[buffer].h;
                if (d < 1.0f) v = strength; else v = strength / sqrt_asm(d);
                if (!add) {
                    f32 old = grid[row][col];
                    if (fabs_asm(v) < fabs_asm(old)) v = old;
                } else v += tile->b[other].h[row][col];
                grid[row][col] = v;
                if (row < 2 && tile->neighbors[0] != 255) {
                    if (!row) ((f32 *)&tiles[tile->neighbors[0]].b[buffer])[col + 288] = grid[0][col];
                    else ((f32 *)&tiles[tile->neighbors[0]].b[buffer])[col + 320] = v;
                }
                if (col < 2 && tile->neighbors[1] != 255) {
                    if (!col) ((f32 *)&tiles[tile->neighbors[1]].b[buffer])[row + 304] = grid[row][0];
                    else ((f32 *)&tiles[tile->neighbors[1]].b[buffer])[row + 336] = grid[row][col];
                }
                if (row == 15 && tile->neighbors[2] != 255) ((f32 *)&tiles[tile->neighbors[2]].b[buffer])[col + 256] = grid[15][col];
                if (col == 15 && tile->neighbors[3] != 255) ((f32 *)&tiles[tile->neighbors[3]].b[buffer])[row + 272] = grid[row][15];
                if (tile->neighbors[4] != 255) {
                    if (!col && !row) ((f32 *)&tiles[tile->neighbors[4]].b[buffer])[355] = grid[0][0];
                    if (col == 1 && !row) ((f32 *)&tiles[tile->neighbors[4]].b[buffer])[356] = grid[0][1];
                    if (!col && row == 1) ((f32 *)&tiles[tile->neighbors[4]].b[buffer])[357] = grid[1][0];
                }
                if (tile->neighbors[5] != 255 && col == 15 && !row) ((f32 *)&tiles[tile->neighbors[5]].b[buffer])[354] = grid[0][15];
                if (tile->neighbors[6] != 255 && !col && row == 15) ((f32 *)&tiles[tile->neighbors[6]].b[buffer])[353] = grid[15][0];
                if (tile->neighbors[7] != 255 && col == 15 && row == col) ((f32 *)&tiles[tile->neighbors[7]].b[buffer])[352] = grid[15][15];
            }
        }
    }
}
/* localdecomp:end func_L01_004C67A0 */
