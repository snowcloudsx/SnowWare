#include "Includes.h"
#include "JNI/Helper/Java.h"
#include "JNI/Helper/JavaLunar.h"

#include "Module/Cheat.h"
#include "Mapper/Mapper.h"
#include <thread>
#include "Module/Step/Step.h"
#include "Module/TimeChanger/TimeChanger.h"
#include "Module/AutoSprint/sprint.h"
#include "Module/Flight/Flight.h"
#include "Module/Fullbright/Fullbright.h"
#include "Module/Velocity/Velocity.h"
#include "Module/SDK.h"
#include "Module/NameChanger/Name.h"
#include <conio.h>
#include "Module/settings/settings.h"
#include "Module/Combat/Bhop/bhop.h"
#include "Module/Combat/Reach/Reach.h"
#include "Module/Combat/AutoClicker/AutoClicker.h"


void Draw_Arraylist()
{
    ImGui::SetNextWindowSize(ImVec2(100.000f, 100.000f), ImGuiCond_Once);
    ImGui::Begin(" ", NULL, 163);

    ImGui::Text("SnowDev");

    ImGui::End();
}



twglSwapBuffers oSwapBuffers = NULL;
WNDPROC oWndProc;
static HWND Window = NULL;
FILE* file{ nullptr };
int init = false;
bool show = false;
bool showtext = false;
int* cheats::newValue = 0;
int moduleIndexY;
bool open_ptr;
BOOL __stdcall hkSwapBuffers(_In_ HDC hDc)
{
    if (init == FALSE)
    {
        glewExperimental = GL_TRUE;
        if (glewInit() == GLEW_OK)
        {
            ImGui::CreateContext();
            ImGuiIO& io = ImGui::GetIO();
            io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
            ImGui_ImplWin32_Init(Window);
            ImGui_ImplOpenGL3_Init();
            init = TRUE;
        }
    }

    if (GetAsyncKeyState(VK_RSHIFT) & 1)
        show = !show;

    if (GetAsyncKeyState(VK_END) & 1) // Unload
    {
        MH_DisableHook(MH_ALL_HOOKS);
        SetWindowLongPtr(Window, GWL_WNDPROC, (LONG_PTR)oWndProc); // Reset WndProc
    }

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();


    if (show)
    {
        Step step;
        TimeChanger time;
        Sprint sprint;
        Flight flight;
        AutoClicker clicker;
        Fullbright gamma;
        Velocity velo;
        NameChanger name;

        Bhop bhop;
        Reach reach;




        ImGui::StyleColorsClassic();

        auto& Style = ImGui::GetStyle();

        Style.WindowRounding = 4.000f;
        Style.PopupRounding = 4.000f;
        Style.FrameRounding = 4.000f;
        Style.ScrollbarRounding = 4.000f;
        Style.DisplaySafeAreaPadding = ImVec2(0.000f, 3.000f);



      




        ImGui::Begin("Player");
        ImGui::Checkbox("Step", &step.enabled);
        if (ImGui::IsItemHovered()) {
            ImGui::SetTooltip("Makes you step higher.");
        }
        if (step.enabled == true) {
            ImGui::Separator();
            ImGui::SliderFloat("Step Height", &step.stepHeight, 0.0f, 10.0f);
            ImGui::Text("Step Height Value: %.3f", step.stepHeight);
            ImGui::Separator();

        }




        ImGui::Checkbox("Sprint", &sprint.enabled);
        if (ImGui::IsItemHovered()) {
            ImGui::SetTooltip("makes you sprint automatically (also known as autoSprint).");
        }
        if (sprint.enabled == true) {
            ImGui::Separator();
            ImGui::Checkbox("blatent", &sprint.blatent);
            ImGui::Separator();

        }
       


        ImGui::Checkbox("Flight", &flight.enabled);
        if (ImGui::IsItemHovered()) {
            // Display additional information when hovered
            ImGui::SetTooltip("makes you fly");
        }
        if (flight.enabled == true) {
            ImGui::Separator();
            ImGui::Checkbox("Spartan Fly", &flight.blatent);
            if (flight.blatent) {
                ImGui::SliderFloat("Speed", &flight.speed, 0.0, 5.0);
            }
            ImGui::Separator();

        }

        ImGui::Checkbox("Bhop", &bhop.enabled);
        if (ImGui::IsItemHovered()) {
            // Display additional information when hovered
            ImGui::SetTooltip("bunnys hop still right?");
        }
        if (bhop.enabled == true) {
            ImGui::Separator();
            ImGui::Checkbox("NCP Bhop", &settings::NCPBHop);
            ImGui::Checkbox("Versus Bhop", &settings::NCPYPort);
            if (settings::NCPYPort) {
                ImGui::SliderFloat("Speed", &bhop.speed, 0.0, 5.0);

            }

            ImGui::Separator();

        }




        ImGui::Checkbox("FullBright", &gamma.enabled);
        if (ImGui::IsItemHovered()) {
            // Display additional information when hovered
            ImGui::SetTooltip("shines some light on the situation...");
        }

        ImGui::Checkbox("NoSlow", &settings::NoSlow);
        if (ImGui::IsItemHovered()) {
            // Display additional information when hovered
            ImGui::SetTooltip("does what it says");
        }

        ImGui::End();
        //player end

        ImGui::Begin("Useless");
        ImGui::Checkbox("TimeChanger", &time.enabled);
        if (ImGui::IsItemHovered()) {
            // Display additional information when hovered
            ImGui::SetTooltip("Sets the time of day.");
        }
        ImGui::SliderInt("Time",&time.time, 0, 18000);

        // Display the current value of the slider
        ImGui::Text("CurrentTime: %.3f", time.time);
        if (time.time == 13000) {
            ImGui::Text("CurrentTime: Night");
        }
        if (time.time == 1000) {
            ImGui::Text("CurrentTime: Day");
        }
        if (time.time == 0) {
            ImGui::Text("Current Time: dawn");
        }
        if (time.time == 6000) {
            ImGui::Text("Current Time: midDay");
        }
        if (time.time == 12000) {
            ImGui::Text("Current Time: Dusk");
        }
        if (time.time == 18000) {
            ImGui::Text("Current Time: midNight");
        }


        
        ImGui::Separator();


        // Check if the button is hovered
       
        ImGui::End();

        ImGui::Begin("Combat");
        ImGui::Checkbox("Reach",&settings::Reach);
        if (ImGui::IsItemHovered()) {
            // Display additional information when hovered
            ImGui::SetTooltip("long arms");
        }
        if (settings::Reach == true) {
            ImGui::Separator();
            ImGui::SliderFloat("Speed", &settings::dist, 0.0, 5.0);
            ImGui::Separator();

        }


        ImGui::Checkbox("Jump Reset", &settings::JumpReset);
        if (ImGui::IsItemHovered()) {
            // Display additional information when hovered
            ImGui::SetTooltip("legit velocity");
        }
        if (settings::JumpReset == true) {
            ImGui::Separator();
            ImGui::SliderInt("Tick", &settings::VeloTicks, 0, 5);
            ImGui::Separator();

        }


        ImGui::Checkbox("AutoClicker", &clicker.enabled);
        if (ImGui::IsItemHovered()) {
            // Display additional information when hovered
            ImGui::SetTooltip("clicks for you");
        }

        ImGui::Separator();

        ImGui::Checkbox("Velocity", &velo.enabled);
        ImGui::SliderInt("X", &velo.Vx, 0, 100);
        ImGui::SliderInt("Y", &velo.Vy, 0, 100);
        ImGui::SliderInt("Z", &velo.Vz, 0, 100);


        if (ImGui::IsItemHovered()) {
            // Display additional information when hovered
            ImGui::SetTooltip("Dont take kb");
        }
        ImGui::Separator();
        char buf[50];
        ImGui::Checkbox("NameChanger", &name.enabled);
        ImGui::InputText("New Name", name.name, sizeof(name.name));

        if (ImGui::IsItemHovered()) {
            // Display additional information when hovered
            ImGui::SetTooltip("Dont take kb");
        }

   }

    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    return oSwapBuffers(hDc);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

    if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
        return true;

    return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

DWORD WINAPI Initalization(__in  LPVOID lpParameter)
{

  
    while (GetModuleHandle("opengl32.dll") == NULL)  { Sleep(100); }
    Sleep(100);

    HMODULE hMod = GetModuleHandle("opengl32.dll");
    if (hMod)
    {
        void* ptr = GetProcAddress(hMod, "wglSwapBuffers");
        MH_Initialize();
        MH_CreateHook(ptr, hkSwapBuffers, reinterpret_cast<void**>(&oSwapBuffers));
        MH_EnableHook(ptr);
        do
            Window = GetProcessWindow();
        while (Window == NULL);
        oWndProc = (WNDPROC)SetWindowLongPtr(Window, GWL_WNDPROC, (LONG_PTR)WndProc);
        return true;
    }
    else
        return false;
}
/*
void InitLunar(void* instance)
{
    AllocConsole();
    SetConsoleTitle("Client");
    freopen_s(&file, "CONOUT$", "w", stdout);
    std::cout << "[+] Init Console" << std::endl;
    lc.GetLoadedClasses();
    jsize count;
    if (JNI_GetCreatedJavaVMs(&lc.vm, 1, &count) != JNI_OK || count == 0) return;
    jint res = lc.vm->GetEnv((void**)&lc.env, JNI_VERSION_1_8);
    if (res == JNI_EDETACHED) res = lc.vm->AttachCurrentThread((void**)&lc.env, nullptr);

    if (lc.env != nullptr)
    {
        while (true)
        {
            if (GetAsyncKeyState(VK_END)) break;
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
    }

    FreeLibraryAndExitThread(static_cast<HMODULE>(instance), 0);
    FreeConsole();

}*/


void initClient(LPVOID param) {
    while (GetModuleHandle("opengl32.dll") == NULL) { Sleep(100); }
    Sleep(100);

    HMODULE hMod = GetModuleHandle("opengl32.dll");
    if (hMod)
    {
        void* ptr = GetProcAddress(hMod, "wglSwapBuffers");
        MH_Initialize();
        MH_CreateHook(ptr, hkSwapBuffers, reinterpret_cast<void**>(&oSwapBuffers));
        MH_EnableHook(ptr);
        do
            Window = GetProcessWindow();
        while (Window == NULL);
        oWndProc = (WNDPROC)SetWindowLongPtr(Window, GWL_WNDPROC, (LONG_PTR)WndProc);
        AllocConsole();
        //SetConsoleCtrlHandler(NULL, true);
        SetConsoleTitle("Client");
        //freopen_s(&file, "CONOUT$", "w", stdout);
        std::cout << "[+] Init Console" << std::endl;
        FILE* fIn;
        FILE* fOut;
        freopen_s(&fIn, "conin$", "r", stdin);
        freopen_s(&fOut, "conout$", "w", stdout);
        freopen_s(&fOut, "conout$", "w", stderr);



        jsize count;

        if (JNI_GetCreatedJavaVMs(&mc.vm, 1, &count) != JNI_OK || count == 0)
            return;

        jint rest = mc.vm->GetEnv((void**)&mc.env, JNI_VERSION_1_6);


        if (rest == JNI_EDETACHED)
            rest = mc.vm->AttachCurrentThread((void**)&mc.env, nullptr);

        if (mc.env != nullptr)
        {
            while (!GetAsyncKeyState(VK_END)) {
                //Mapper::StartUp();

                cheats::onModuleTick();
            }
           mc.vm->DetachCurrentThread();
           FreeConsole();
        }


            
    }   
}
            
        
    


BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
       //CreateThread(0, 0, (LPTHREAD_START_ROUTINE)InitLunar, 0, 0, 0);
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)initClient, 0, 0, 0);

    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

