// xunilGub.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

int main(void)
{
	/* enable functions */
	// bool	ENABLE_TLS_CHECKS = true;
	bool ENABLE_DEBUG_CHECKS = true;
	// bool	ENABLE_INJECTION_CHECKS = true;
	bool ENABLE_GEN_SANDBOX_CHECKS = true;
	bool ENABLE_VBOX_CHECKS = true;
	bool ENABLE_VMWARE_CHECKS = true;
	bool ENABLE_QEMU_CHECKS = true;
	bool ENABLE_XEN_CHECKS = true;
	// bool	ENABLE_PARALLELS_CHECKS = true;
	// bool	ENABLE_CODE_INJECTIONS = false;
	bool ENABLE_TIMING_ATTACKS = true;
	// bool	ENABLE_DUMPING_CHECK = true;
	// bool	ENABLE_ANALYSIS_TOOLS_CHECK = true;
	bool ENABLE_ANTI_DISASSM_CHECKS = true;
	


	// /* Resize the console window for better visibility */
	// resize_console_window();

	// /* Display general informations */
	// _tprintf(_T("[al-khaser version 0.80]"));

	// print_category(TEXT("Initialisation"));
	// API::Init();
	// print_os();
	// API::PrintAvailabilityReport();

	// /* Are we running under WoW64 */
	// if (IsWoW64())
	// 	_tprintf(_T("Process is running under WOW64\n\n"));

	// if (ENABLE_DEBUG_CHECKS) PageExceptionInitialEnum();

	// /* TLS checks */
	// if (ENABLE_TLS_CHECKS) {
	// }

	/* Debugger Detection */
	if (ENABLE_DEBUG_CHECKS) {
		std::cout << "Debugger Detection" << std::endl;
		std::system("./debugmenot/src/debugmenot");
		//exec_check(&IsDebuggerPresentAPI, TEXT("Checking IsDebuggerPresent API "));
	}

	// if (ENABLE_INJECTION_CHECKS) {
	// }

	// /* Generic sandbox detection */
	if (ENABLE_GEN_SANDBOX_CHECKS) {
		std::cout << "Sandbox Detection" << std::endl;
		std::cout << " Mouse movement (check in /dev/input/mice)" <<  std::flush << ((mouse_movement() == 0) ? "PASS" : "FAIL") << std::endl; // check again if logic is correct: move -> PASS, not move -> FAIL
		std::cout << " Mouse movement (check using xdottools)" <<  std::flush << ((mouse_movement_tool() == 0) ? "PASS" : "FAIL") << std::endl; // check again if logic is correct: move -> PASS, not move -> FAIL		
		std::cout << " Checking Number of processors in machine " << ((number_of_processors()== 0) ? "PASS" : "FAIL") << std::endl;
		std::cout << " Checking Interupt Descriptor Table location " << ((idt_trick()== 0) ? "PASS" : "FAIL") << std::endl;
		std::cout << " Checking Local Descriptor Table location " << ((ldt_trick()== 0) ? "PASS" : "FAIL") << std::endl;
		std::cout << " Checking Global Descriptor Table location " << ((gdt_trick()== 0) ? "PASS" : "FAIL") << std::endl;
		std::cout << " Checking disk space using std::filesystem::space_info " << ((disk_space() == 0) ? "PASS" : "FAIL") << std::endl; // true -> fail, false -> pass
		std::cout << " Check if time has been accelerated " << ((accelerated_sleep() == 0) ? "PASS" : "FAIL") << std::endl; // true -> fail, false -> pass
		std::cout << " Checking memory ram space " << ((memory_space() == 0) ? "PASS" : "FAIL") << std::endl; // true -> fail, false -> pass
		std::cout << " Checking model vendor name " << ((model_computer_system() == 0) ? "PASS" : "FAIL") << std::endl; // true -> fail, false -> pass
	}

	/* VirtualBox Detection */
	if (ENABLE_VBOX_CHECKS) {
		std::cout << "Virtual Box Detection" << std::endl;
		std::cout << " Checking mac address " << ((vbox_check_mac() == 0) ? "PASS" : "FAIL") << std::endl; // true -> fail, false -> pass
		std::cout << " Checking pseudo devices " << ((vbox_check_devices() == 0) ? "PASS" : "FAIL") << std::endl; // true -> fail, false -> pass
		std::cout << " Checking vbox files " << ((vbox_check_files() == 0) ? "PASS" : "FAIL") << std::endl; // true -> fail, false -> pass
		std::cout << " Checking vbox processes " << ((vbox_check_processes() == 0) ? "PASS" : "FAIL") << std::endl; // true -> fail, false -> pass
		std::cout << " Checking vbox firmware " << ((vbox_check_firmware() == 0) ? "PASS" : "FAIL") << std::endl; // true -> fail, false -> pass
	}

	/* VMWare Detection */
	if (ENABLE_VMWARE_CHECKS) {
		std::cout << "VMWare Detection" << std::endl;
		std::cout << " Checking mac address " << ((vmware_check_mac() == 0) ? "PASS" : "FAIL") << std::endl; // true -> fail, false -> pass
		std::cout << " Checking vmware firmware " << ((vmware_check_firmware() == 0) ? "PASS" : "FAIL") << std::endl; // true -> fail, false -> pass
		std::cout << " Checking vmware pseudo devices " << ((vmware_check_devices() == 0) ? "PASS" : "FAIL") << std::endl; // true -> fail, false -> pass
		std::cout << " Checking vmware files " << ((vmware_check_files() == 0) ? "PASS" : "FAIL") << std::endl; // true -> fail, false -> pass
		std::cout << " Checking vmware processes " << ((vmware_check_processes() == 0) ? "PASS" : "FAIL") << std::endl; // true -> fail, false -> pass
		
	}

	/* QEMU Detection */
	if (ENABLE_QEMU_CHECKS) {
		std::cout << "Qemu Detection" << std::endl;
		std::cout << " Checking qemu firmware " << ((qemu_check_firmware() == 0) ? "PASS" : "FAIL") << std::endl; // true -> fail, false -> pass
	}

	/* Xen Detection */
	if (ENABLE_XEN_CHECKS) {
		std::cout << "xen Detection" << std::endl;
		std::cout << " Checking xen mac address " << ((xen_check_mac() == 0) ? "PASS" : "FAIL") << std::endl; // true -> fail, false -> pass
	}

	// /* Paralles Detection */
	// if (ENABLE_PARALLELS_CHECKS) {
	// }

	// /* Code injections techniques */
	// if (ENABLE_CODE_INJECTIONS) {
	// }

	/* Timing Attacks */
	if (ENABLE_TIMING_ATTACKS) {
		std::cout << "Timing attacks" << std::endl;
		std::cout << " Performing a sleep() in a loop ..." << ((timing_sleep_loop(1000) == 0) ? "PASS" : "FAIL") << std::endl; // true -> fail, false -> pass
		std::cout << " Performing a sleep() exploiting ping command line to un existing address " << ((timing_IcmpSendEcho(3) == 0) ? "PASS" : "FAIL") << std::endl; // true -> fail, false -> pass
		
		
	}

	// /* Malware analysis tools */
	// if (ENABLE_ANALYSIS_TOOLS_CHECK) {
	// }

	/* Anti disassembler tricks */
	if (ENABLE_ANTI_DISASSM_CHECKS) {
		std::cout << "Anti disassembler checks" << std::endl;
		std::cout<< " Begin AntiDisassmConstantCondition"<<std::endl;
		AntiDisassmConstantCondition();
		std::cout<< " Begin AntiDisassmAsmJmpSameTarget"<<std::endl;
		AntiDisassmAsmJmpSameTarget();
		
	}

	// /* Anti Dumping */
	// if (ENABLE_DUMPING_CHECK) {
	// }

    
	std::cout << "\n\nAnalysis done, I hope you didn't get red flags :)" << std::endl;

	return 0;
}