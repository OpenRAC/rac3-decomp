/* PAL near miss (Codex wave 6): near miss: 149 words differ with the file's flags.
 * Worker's note: Best 89 diff in w319/func_L01_004C6D40.07.log (divs injected 2,2,2,2, not MATCH). Register copies/grid indexing and final global loads; ten compiles. Retained v7 source.
 */
#include "common.h"
/* localdecomp:start func_L01_004C6D40 */
typedef struct { float grid[16][16]; u8 pad400[0x80]; float edgeY[16]; float edgeX[16]; u8 pad500[0x8C]; float corner; u8 pad590[0x30]; } Layer_004C6D40;
typedef struct {
    float x, y, z;
    u8 pad[0x50-12];
    Layer_004C6D40 cells[3];
} Tile_004C6D40;
extern Tile_004C6D40 *D_L01_001E1090;
extern float D_L01_001DAEA8, D_L01_001DAEAC, D_L01_001DAEB0, D_L01_001DAEB4;
__asm__(".extern D_L01_001DAEB0, 16");
extern int D_001DAE88_sda;
__asm__(".extern D_001DAE88_sda, 4");
int func_L01_004C6D40(float *height, Vec4_004C4AD8 *normal, float x, float y) {
    extern int func_L01_004C6620(float, float);
    extern void func_0038CE90(Vec4_004C4AD8 *, Vec4_004C4AD8 *, T_004C4AD8 *);
    extern void func_0038CF68(Vec4_004C4AD8 *, Vec4_004C4AD8 *, float);
    Vec4_004C4AD8 dx, dy;
    Tile_004C6D40 *tile;
    float (*grid)[16];
    int layerOffset;
    int idx, ix, iy, layer;
    float rx, ry, u, v, a, b, c, d, bottom, top;
    idx = func_L01_004C6620(x, y);
    if (idx < 0) return 0;
    tile = &D_L01_001E1090[idx];
    rx = x - (tile->x + D_L01_001DAEA8);
    ry = y - (tile->y + D_L01_001DAEAC);
    ix = (int)(rx / D_L01_001DAEB0);
    iy = (int)(ry / D_L01_001DAEB4);
    u = (rx - (float)ix * D_L01_001DAEB0) / D_L01_001DAEB0;
    v = (ry - (float)iy * D_L01_001DAEB4) / D_L01_001DAEB4;
    grid = (void *)tile->cells;
    layerOffset = D_001DAE88_sda * 0x5C0;
    a = *(float *)((u8 *)grid + ((ix<<2) + (iy<<6) + layerOffset));
    if (ix == 15) b = *(float *)((u8 *)tile + ((iy<<2) + layerOffset) + 0x510);
    else b = *(float *)((u8 *)grid + (((ix+1)<<2) + (iy<<6) + layerOffset));
    layer = D_001DAE88_sda;
    if (iy == 15) c = tile->cells[layer].edgeY[ix];
    else c = tile->cells[layer].grid[iy+1][ix];
    if (ix == 15) {
        if (iy == 15) d = tile->cells[layer].corner;
        else d = tile->cells[layer].edgeX[iy+1];
    } else {
        if (iy == 15) d = tile->cells[layer].edgeY[ix+1];
        else d = tile->cells[layer].grid[iy+1][ix+1];
    }
    if (height) {
        bottom = a + (b-a)*u;
        top = c + (d-c)*u;
        *height = bottom + (top-bottom)*v + tile->z;
    }
    if (normal) {
        dx.x = D_L01_001DAEB0; dx.y = 0.0f; dx.z = b-a; dx.w = 1.0f;
        dy.x = 0.0f; dy.y = D_L01_001DAEB4; dy.z = c-a; dy.w = 1.0f;
        func_0038CE90(normal, &dx, (T_004C4AD8 *)&dy);
        func_0038CF68(normal, normal, 1.0f);
    }
    return 1;
}
/* localdecomp:end func_L01_004C6D40 */
