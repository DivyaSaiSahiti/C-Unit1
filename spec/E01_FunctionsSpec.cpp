#include "stdafx.h"

#include "../src/E01_Functions.cpp"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

namespace spec
{
    [TestClass]
    public ref class E01_FunctionsSpec
    {
    private:
        TestContext^ testContextInstance;
        
    public:
        /// <summary>
        ///Gets or sets the test context which provides
        ///information about and functionality for the current test run.
        ///</summary>
        property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
        {
            Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
            {
                return testContextInstance;
            }
            System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
            {
                testContextInstance = value;
            }
        };
        
        
        [TestMethod, Timeout(3000)]
        void Test_midPoint()
        {
            
            Assert::AreEqual(3, midPoint(2, 4), L"midPoint(2, 4) failed", 1, 2);
            
            Assert::AreEqual(0x8FFFFFFF, midPoint(0x8FFFFFFF, 0x8FFFFFFF), L"midPoint(0x8FFFFFFF, 0x8FFFFFFF) failed", 1, 2);
        };
    };
}
