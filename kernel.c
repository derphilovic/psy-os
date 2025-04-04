void kernel_main() {
    volatile unsigned short *vga = (volatile unsigned short*)0xB8000;
    const char *msg = 
        " ________  ________       ___    ___      ________  ________      \n"
        "|\\   __  \\|\\   ____\\     |\\  \\  /  /|    |\\   __  \\|\\   ____\\     \n"
        "\\ \\  \\|\\  \\ \\  \\___|_    \\ \\  \\/  / /    \\ \\  \\|\\  \\ \\  \\___|_    \n"
        " \\ \\   ____\\ \\_____  \\    \\ \\    / /      \\ \\  \\\\\\  \\ \\_____  \\   \n"
        "  \\ \\  \\___|\\|____|\\  \\    \\/  /  /        \\ \\  \\\\\\  \\|____|\\  \\  \n"
        "   \\ \\__\\     ____\\_\\  \\ __/  / /           \\ \\_______\\____\\_\\  \\ \n"
        "    \\|__|    |\\_________\\\\___/ /             \\|_______|\\_________\\\n"
        "             \\|_________\\|___|/                       \\|_________|\n";
    
    unsigned int i = 0;
    unsigned int vga_idx = 0;
    
    while (msg[i] != '\0') {
        if (msg[i] == '\n') {
            vga_idx += 80 - (vga_idx % 80);
        } else {
            vga[vga_idx] = (0x0F << 8) | msg[i];
            vga_idx++;
        }
        i++;
    }

    // Halt CPU
    while(1) __asm__("hlt");
}