#pragma once

/*
GPU selection:
	0x00000000 - integrated graphics card
	0x00000001 - primary GPU
*/
extern "C" {
	_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000000;
}