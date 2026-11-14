// Licensed under GPLv3 or any later version
// Refer to the LICENSE.txt file included.

// Moonfix: unofficial per-title workaround, not part of upstream Azahar.
#pragma once

#include <atomic>

namespace VideoCore {

/// Set per title by GPU::ApplyPerProgramSettings. When true, a surface whose invalid region is
/// owned by a GPU-modified surface with a different memory layout (tiled vs linear) is not
/// refreshed through guest memory. This extends the existing stride-mismatch heuristic in
/// RasterizerCache::ValidateByReinterpretation. Moon Chronicles reuses one VRAM block as a linear
/// downscale target and then as its tiled final framebuffer every frame; refreshing the
/// framebuffer from that stale block costs a GPU readback per frame and the game overwrites it
/// with a full-screen quad anyway.
inline std::atomic<bool> g_skip_layout_mismatch_validation{false};

} // namespace VideoCore
