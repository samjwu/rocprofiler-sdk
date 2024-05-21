// MIT License
//
// Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <string>
#include <unordered_map>
#include <vector>

// Expected values for GFX908. GFX908 was chosen because it is not the first
// arch defined in the XML and it is also an arch that inherits values (from gfx9)
// Layout is: {name, block, event, expression, description}.
static const std::unordered_map<std::string, std::vector<std::vector<std::string>>> basic_gfx908 = {
    {"gfx908",
     {{"MAX_WAVE_SIZE", "", "", "1", "Max wave size constant"},
      {"SE_NUM", "", "", "1", "SE_NUM"},
      {"SIMD_NUM", "", "", "1", "SIMD Number"},
      {"CU_NUM", "", "", "1", "CU_NUM"},
      {"SQ_INSTS_VMEM_WR",
       "SQ",
       "28",
       "<None>",
       "Number of VMEM write instructions issued (including FLAT). (per-simd, emulated)"},
      {"SQ_INSTS_VMEM_RD",
       "SQ",
       "29",
       "<None>",
       "Number of VMEM read instructions issued (including FLAT). (per-simd, emulated)"},
      {"SQ_INSTS_SALU",
       "SQ",
       "31",
       "<None>",
       "Number of SALU instructions issued. (per-simd, emulated)"},
      {"SQ_INSTS_SMEM",
       "SQ",
       "32",
       "<None>",
       "Number of SMEM instructions issued. (per-simd, emulated)"},
      {"SQ_INSTS_FLAT",
       "SQ",
       "33",
       "<None>",
       "Number of FLAT instructions issued. (per-simd, emulated)"},
      {"SQ_INSTS_FLAT_LDS_ONLY",
       "SQ",
       "34",
       "<None>",
       "Number of FLAT instructions issued that read/wrote only from/to LDS (only works if "
       "EARLY_TA_DONE is enabled). (per-simd, emulated)"},
      {"SQ_INSTS_LDS",
       "SQ",
       "35",
       "<None>",
       "Number of LDS instructions issued (including FLAT). (per-simd, emulated)"},
      {"SQ_INSTS_GDS",
       "SQ",
       "36",
       "<None>",
       "Number of GDS instructions issued. (per-simd, emulated)"},
      {"SQ_WAIT_INST_LDS",
       "SQ",
       "64",
       "<None>",
       "Number of wave-cycles spent waiting for LDS instruction issue. In units of 4 cycles. "
       "(per-simd, nondeterministic)"},
      {"SQ_ACTIVE_INST_VALU",
       "SQ",
       "72",
       "<None>",
       "regspec 71? Number of cycles the SQ instruction arbiter is working on a VALU instruction. "
       "(per-simd, nondeterministic). Units in quad-cycles(4 cycles)"},
      {"SQ_INST_CYCLES_SALU",
       "SQ",
       "85",
       "<None>",
       "Number of cycles needed to execute non-memory read scalar operations. (per-simd, "
       "emulated)"},
      {"SQ_THREAD_CYCLES_VALU",
       "SQ",
       "86",
       "<None>",
       "Number of thread-cycles used to execute VALU operations (similar to INST_CYCLES_VALU but "
       "multiplied by # of active threads). (per-simd)"},
      {"SQ_LDS_BANK_CONFLICT",
       "SQ",
       "94",
       "<None>",
       "Number of cycles LDS is stalled by bank conflicts. (emulated)"},
      {"TCC_HIT", "TCC", "17", "<None>", "Number of cache hits."},
      {"TCC_MISS", "TCC", "19", "<None>", "Number of cache misses. UC reads count as misses."},
      {"TCC_EA_WRREQ",
       "TCC",
       "26",
       "<None>",
       "Number of transactions (either 32-byte or 64-byte) going over the TC_EA_wrreq interface. "
       "Atomics may travel over the same interface and are generally classified as write requests. "
       "This does not include probe commands."},
      {"TCC_EA_WRREQ_64B",
       "TCC",
       "27",
       "<None>",
       "Number of 64-byte transactions going (64-byte write or CMPSWAP) over the TC_EA_wrreq "
       "interface."},
      {"TCC_EA_WRREQ_STALL",
       "TCC",
       "30",
       "<None>",
       "Number of cycles a write request was stalled."},
      {"TCC_EA_RDREQ",
       "TCC",
       "38",
       "<None>",
       "Number of TCC/EA read requests (either 32-byte or 64-byte)"},
      {"TCC_EA_RDREQ_32B", "TCC", "39", "<None>", "Number of 32-byte TCC/EA read requests"},
      {"GRBM_COUNT", "GRBM", "0", "<None>", "Tie High - Count Number of Clocks"},
      {"GRBM_GUI_ACTIVE", "GRBM", "2", "<None>", "The GUI is Active"},
      {"SQ_WAVES",
       "SQ",
       "4",
       "<None>",
       "Count number of waves sent to SQs. (per-simd, emulated, global)"},
      {"SQ_INSTS_VALU",
       "SQ",
       "26",
       "<None>",
       "Number of VALU instructions issued. (per-simd, emulated)"},
      {"TA_TA_BUSY",
       "TA",
       "15",
       "<None>",
       "TA block is busy. Perf_Windowing not supported for this counter."},
      {"TA_FLAT_READ_WAVEFRONTS",
       "TA",
       "101",
       "<None>",
       "Number of flat opcode reads processed by the TA."},
      {"TA_FLAT_WRITE_WAVEFRONTS",
       "TA",
       "102",
       "<None>",
       "Number of flat opcode writes processed by the TA."},
      {"TCP_TCP_TA_DATA_STALL_CYCLES",
       "TCP",
       "6",
       "<None>",
       "TCP stalls TA data interface. Now Windowed."}}}};

static const std::unordered_map<std::string, std::vector<std::vector<std::string>>> derived_gfx908 =
    {{"gfx908",
      {{"GPU_UTIL",
        "",
        "",
        "100*GRBM_GUI_ACTIVE/GRBM_COUNT",
        "Percentage of the time that GUI is active"},
       {"SQ_WAVES_sum",
        "",
        "",
        "reduce(SQ_WAVES,sum)",
        "Count number of waves sent to SQs. (per-simd, emulated, global). Sum over SQ instances."},
       {"TCC_HIT_sum",
        "",
        "",
        "reduce(TCC_HIT,sum)",
        "Number of cache hits. Sum over TCC instances."},
       {"TCC_MISS_sum",
        "",
        "",
        "reduce(TCC_MISS,sum)",
        "Number of cache misses. Sum over TCC instances."},
       {"TCC_EA_RDREQ_32B_sum",
        "",
        "",
        "reduce(TCC_EA_RDREQ_32B,sum)",
        "Number of 32-byte TCC/EA read requests. Sum over TCC instances."},
       {"TCC_EA_RDREQ_sum",
        "",
        "",
        "reduce(TCC_EA_RDREQ,sum)",
        "Number of TCC/EA read requests (either 32-byte or 64-byte). Sum over TCC instances."},
       {"TCC_EA_WRREQ_sum",
        "",
        "",
        "reduce(TCC_EA_WRREQ,sum)",
        "Number of transactions (either 32-byte or 64-byte) going over the TC_EA_wrreq "
        "interface. Sum over TCC instances."},
       {"TCC_EA_WRREQ_64B_sum",
        "",
        "",
        "reduce(TCC_EA_WRREQ_64B,sum)",
        "Number of 64-byte transactions going (64-byte write or CMPSWAP) over the TC_EA_wrreq "
        "interface. Sum over TCC instances."},
       {"TCC_WRREQ_STALL_max",
        "",
        "",
        "reduce(TCC_EA_WRREQ_STALL,max)",
        "Number of cycles a write request was stalled. Max over TCC instances."},
       {"CU_UTILIZATION",
        "",
        "",
        "GRBM_GUI_ACTIVE/GRBM_COUNT",
        "The total number of active cycles divided by total number of elapsed cycles"},
       {"TA_BUSY_avr",
        "",
        "",
        "reduce(TA_TA_BUSY,avr)",
        "TA block is busy. Average over TA instances."},
       {"TA_BUSY_max",
        "",
        "",
        "reduce(TA_TA_BUSY,max)",
        "TA block is busy. Max over TA instances."},
       {"TA_BUSY_min",
        "",
        "",
        "reduce(TA_TA_BUSY,min)",
        "TA block is busy. Min over TA instances."},
       {"TA_FLAT_READ_WAVEFRONTS_sum",
        "",
        "",
        "reduce(TA_FLAT_READ_WAVEFRONTS,sum)",
        "Number of flat opcode reads processed by the TA. Sum over TA instances."},
       {"TA_FLAT_WRITE_WAVEFRONTS_sum",
        "",
        "",
        "reduce(TA_FLAT_WRITE_WAVEFRONTS,sum)",
        "Number of flat opcode writes processed by the TA. Sum over TA instances."},
       {"TCP_TCP_TA_DATA_STALL_CYCLES_sum",
        "",
        "",
        "reduce(TCP_TCP_TA_DATA_STALL_CYCLES,sum)",
        "Total number of TCP stalls TA data interface."},
       {"TCP_TCP_TA_DATA_STALL_CYCLES_max",
        "",
        "",
        "reduce(TCP_TCP_TA_DATA_STALL_CYCLES,max)",
        "Maximum number of TCP stalls TA data interface."},
       {"FETCH_SIZE",
        "",
        "",
        "(TCC_EA_RDREQ_32B_sum*32+(TCC_EA_RDREQ_sum-TCC_EA_RDREQ_32B_sum)*64)/1024",
        "The total kilobytes fetched from the video memory. This is measured with all extra "
        "fetches and any cache or memory effects taken into account."},
       {"WRITE_SIZE",
        "",
        "",
        "((TCC_EA_WRREQ_sum-TCC_EA_WRREQ_64B_sum)*32+TCC_EA_WRREQ_64B_sum*64)/1024",
        "The total kilobytes written to the video memory. This is measured with all extra "
        "fetches and any cache or memory effects taken into account."},
       {"WRITE_REQ_32B",
        "",
        "",
        "TCC_EA_WRREQ_64B_sum*2+(TCC_EA_WRREQ_sum-TCC_EA_WRREQ_64B_sum)",
        "The total number of 32-byte effective memory writes."},
       {"VFetchInsts",
        "",
        "",
        "(SQ_INSTS_VMEM_RD-TA_FLAT_READ_WAVEFRONTS_sum)/SQ_WAVES",
        "The average number of vector fetch instructions from the video memory executed per "
        "work-item (affected by flow control). Excludes FLAT instructions that fetch from video "
        "memory."},
       {"VWriteInsts",
        "",
        "",
        "(SQ_INSTS_VMEM_WR-TA_FLAT_WRITE_WAVEFRONTS_sum)/SQ_WAVES",
        "The average number of vector write instructions to the video memory executed per "
        "work-item (affected by flow control). Excludes FLAT instructions that write to video "
        "memory."},
       {"FlatVMemInsts",
        "",
        "",
        "(SQ_INSTS_FLAT-SQ_INSTS_FLAT_LDS_ONLY)/SQ_WAVES",
        "The average number of FLAT instructions that read from or write to the video memory "
        "executed per work item (affected by flow control). Includes FLAT instructions that "
        "read from or write to scratch."},
       {"LDSInsts",
        "",
        "",
        "(SQ_INSTS_LDS-SQ_INSTS_FLAT_LDS_ONLY)/SQ_WAVES",
        "The average number of LDS read or LDS write instructions executed per work item "
        "(affected by flow control).  Excludes FLAT instructions that read from or write to "
        "LDS."},
       {"FlatLDSInsts",
        "",
        "",
        "SQ_INSTS_FLAT_LDS_ONLY/SQ_WAVES",
        "The average number of FLAT instructions that read or write to LDS executed per work "
        "item (affected by flow control)."},
       {"VALUUtilization",
        "",
        "",
        "100*SQ_THREAD_CYCLES_VALU/(SQ_ACTIVE_INST_VALU*MAX_WAVE_SIZE)",
        "The percentage of active vector ALU threads in a wave. A lower number can mean either "
        "more thread divergence in a wave or that the work-group size is not a multiple of 64. "
        "Value range: 0\% (bad), 100\% (ideal - no thread divergence)."},
       {"VALUBusy",
        "",
        "",
        "100*SQ_ACTIVE_INST_VALU*4/SIMD_NUM/GRBM_GUI_ACTIVE",
        "The percentage of GPUTime vector ALU instructions are processed. Value range: 0\% "
        "(bad) to 100\% (optimal)."},
       {"SALUBusy",
        "",
        "",
        "100*SQ_INST_CYCLES_SALU*4/SIMD_NUM/GRBM_GUI_ACTIVE",
        "The percentage of GPUTime scalar ALU instructions are processed. Value range: 0% (bad) "
        "to 100% (optimal)."},
       {"FetchSize",
        "",
        "",
        "FETCH_SIZE",
        "The total kilobytes fetched from the video memory. This is measured with all extra "
        "fetches and any cache or memory effects taken into account."},
       {"WriteSize",
        "",
        "",
        "WRITE_SIZE",
        "The total kilobytes written to the video memory. This is measured with all extra "
        "fetches and any cache or memory effects taken into account."},
       {"MemWrites32B",
        "",
        "",
        "WRITE_REQ_32B",
        "The total number of effective 32B write transactions to the memory"},
       {"L2CacheHit",
        "",
        "",
        "100*reduce(TCC_HIT,sum)/(reduce(TCC_HIT,sum)+reduce(TCC_MISS,sum))",
        "The percentage of fetch, write, atomic, and other instructions that hit the data in L2 "
        "cache. Value range: 0\% (no hit) to 100\% (optimal)."},
       {"MemUnitStalled",
        "",
        "",
        "100*TCP_TCP_TA_DATA_STALL_CYCLES_max/GRBM_GUI_ACTIVE/SE_NUM",
        "The percentage of GPUTime the memory unit is stalled. Try reducing the number or size "
        "of fetches and writes if possible. Value range: 0\% (optimal) to 100\% (bad)."},
       {"WriteUnitStalled",
        "",
        "",
        "100*TCC_WRREQ_STALL_max/GRBM_GUI_ACTIVE",
        "The percentage of GPUTime the Write unit is stalled. Value range: 0\% to 100\% (bad)."},
       {"LDSBankConflict",
        "",
        "",
        "100*SQ_LDS_BANK_CONFLICT/GRBM_GUI_ACTIVE/CU_NUM",
        "The percentage of GPUTime LDS is stalled by bank conflicts. Value range: 0\% (optimal) "
        "to 100\% (bad)."}}}};
