#include "pch.h"
#include "File.h"
#include <msclr\marshal_cppstd.h>
#include "FormQint.h"

using namespace System::Windows::Forms;
int __clrcall main(cli::array<System::String^>^ args)
{
	if (args->Length == 3) 
	{
		vector<std::string> result(args->Length);
		auto a0 = args[0];
		auto a1 = args[1];
		auto a2 = args[2];
		msclr::interop::marshal_context^ context = gcnew msclr::interop::marshal_context();
		const char* ar0=context->marshal_as<const char*>(a0);
		const char* ar1 = context->marshal_as<const char*>(a1);
		const char* ar2 = context->marshal_as<const char*>(a2);
		File f;
		f.input((char*)ar0, (char*)ar1, (ar2[0] -'0'));
		delete context;
	}
	else {
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Application::Run(gcnew CppCLRWinformsProjekt::FormQint());
	}
	
	
	return 0;
}