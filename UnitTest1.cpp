#include "pch.h"
#include "CppUnitTest.h"
#include "../16.04/product.h"
#include "../16.04/order.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests1
{
	TEST_CLASS(UnitTests1)
	{
	public:

		TEST_METHOD(TestProductConstructor)
		{
			Product p(1, "Milk", 50, "Food");

			Assert::AreEqual(1, p.getId());
			Assert::AreEqual(std::string("Milk"), p.getName());
			Assert::AreEqual(50.0, p.getPrice());
			Assert::AreEqual(std::string("Food"), p.getCategory());
		}

		TEST_METHOD(TestDefaultProduct)
		{
			Product p;

			Assert::AreEqual(0, p.getId());
			Assert::AreEqual(std::string(""), p.getName());
			Assert::AreEqual(0.0, p.getPrice());
			Assert::AreEqual(std::string(""), p.getCategory());
		}

		TEST_METHOD(TestAddProduct)
		{
			Order order;

			Product p(1, "Bread", 30, "Food");

			order.addProduct(p, 2);

			Assert::AreEqual(60.0, order.getTotal());
		}

		TEST_METHOD(TestAddSameProduct)
		{
			Order order;

			Product p(1, "Bread", 30, "Food");

			order.addProduct(p, 2);
			order.addProduct(p, 3);

			Assert::AreEqual(150.0, order.getTotal());
		}

		TEST_METHOD(TestRemoveProduct)
		{
			Order order;

			Product p1(1, "Milk", 50, "Food");
			Product p2(2, "Juice", 40, "Drink");

			order.addProduct(p1, 2);
			order.addProduct(p2, 1);

			order.removeProduct(1);

			Assert::AreEqual(40.0, order.getTotal());
		}

		TEST_METHOD(TestChangeQuantity)
		{
			Order order;

			Product p(1, "Milk", 50, "Food");

			order.addProduct(p, 1);

			order.changeQuantity(1, 5);

			Assert::AreEqual(250.0, order.getTotal());
		}

		TEST_METHOD(TestPromoSAVE10)
		{
			Order order;

			Product p(1, "Milk", 100, "Food");

			order.addProduct(p, 1);

			order.applyPromo("SAVE20");

			Assert::AreEqual(90.0, order.getTotal());
		}

		TEST_METHOD(TestPromoSAVE20)
		{
			Order order;

			Product p(1, "Milk", 100, "Food");

			order.addProduct(p, 1);

			order.applyPromo("SAVE20");

			Assert::AreEqual(80.0, order.getTotal());
		}

		TEST_METHOD(TestWrongPromo)
		{
			Order order;

			Product p(1, "Milk", 100, "Food");

			order.addProduct(p, 1);

			order.applyPromo("ABC");

			Assert::AreEqual(100.0, order.getTotal());
		}

		TEST_METHOD(TestSaveAndLoad)
		{
			Order order1;

			Product p(1, "Milk", 50, "Food");

			order1.addProduct(p, 2);

			order1.saveToFile("test.json");

			Order order2;

			order2.loadFromFile("test.json");

			Assert::AreEqual(100.0, order2.getTotal());
		}
	};
}