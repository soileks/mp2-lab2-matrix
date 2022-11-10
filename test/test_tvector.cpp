
#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
	

  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)

{
	TDynamicVector<int> v1(10);
	TDynamicVector<int> v2(v1);
	EXPECT_EQ(true, v1 == v2);
  
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> v1(10);
	TDynamicVector<int> v2(v1);
	EXPECT_EQ(false, &v1==&v2);
  
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
  TDynamicVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(10);
	ASSERT_ANY_THROW(v.at(-3));
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(10);
	ASSERT_ANY_THROW(v.at(1000));
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v(2);
	ASSERT_NO_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	const size_t size = 2;
	TDynamicVector<int> v1(size), v2(size);
	v1[0] = 0;
	v1[1] = 1;
	v2[0] = 1;
	v2[1] = 0;
	v2 = v1;
	EXPECT_EQ(0, v2[0]);
	EXPECT_EQ(1, v2[1]);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	const size_t size1 = 2, size2 = 5;
	TDynamicVector<int> v1(size1), v2(size2);
	v2 = v1;
	EXPECT_EQ(size1, v2.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	const size_t size1 = 2, size2 = 1;
	TDynamicVector<int> v1(size1), v2(size2);
	v1[0] = 0;
	v1[1] = 1;
	v2[0] = 100;
	v2 = v1;
	EXPECT_EQ(0, v2[0]);
	EXPECT_EQ(1, v2[1]);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> v1(3);
	TDynamicVector<int> v2(3);
	v1[0] = 0;
	v1[1] = 1;
	v1[2] = 2;
	v2[0] = 0;
	v2[1] = 1;
	v2[2] = 2;
	EXPECT_EQ(true, v1 == v2);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> v(10);
	EXPECT_EQ(true, v == v);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> v1(5), v2(10);
	EXPECT_EQ(true, v1 != v2);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	/*const size_t size = 5;
	const int scalar = 2;
	TDynamicVector<int> v1(size), v2(size);
	for (size_t i = 0; i < size; i++)
	{
		v1[i] = i;
		v2[i] = i + scalar;
	}
	v1 = v1 + scalar;
	EXPECT_EQ(true, v1 == v2);*/
	TDynamicVector<int> v(4);
	v[0] = 5;
	v = v + 5;
	EXPECT_EQ(10, v[0]);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
  /*const size_t size = 5;
  const int scalar = 2;
  TDynamicVector<int> v1(size), v2(size);
  for (size_t i = 0; i < size; i++)
  {
	  v1[i] = i;
	  v2[i] = i - scalar;
  }
  v1 = v1 - scalar;
  EXPECT_EQ(true, v1 == v2);*/
	TDynamicVector<int> v(4);
	v[0] = 5;
	v = v - 5;
	EXPECT_EQ(0, v[0]);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	/*const size_t size = 5;
	const int scalar = 2;
	TDynamicVector<int> v1(size), v2(size);
	for (size_t i = 0; i < size; i++)
	{
		v1[i] = i;
		v2[i] = i * scalar;
	}
	v1 = v1 * scalar;
	EXPECT_EQ(true, v1 == v2);*/
	TDynamicVector<int> v(4);
	v[0] = 5;
	v = v * 5;
	EXPECT_EQ(25, v[0]);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	const size_t size = 5;
	TDynamicVector<int> v1(size), v2(size), v3(size);
	for (size_t i = 0; i < size; i++)
	{
		v1[i] = 2;
		v2[i] = 5;
		v3[i] = v1[i] + v2[i];
	}
	EXPECT_EQ(true, (v1 + v2) == v3);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	const size_t size1 = 5, size2 = 10;
	TDynamicVector<int> v1(size1), v2(size2);
	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	const size_t size = 5;
	TDynamicVector<int> v1(size), v2(size), v3(size);
	for (size_t i = 0; i < size; i++)
	{
		v1[i] = 2;
		v2[i] = 5;
		v3[i] = v1[i] - v2[i];
	}
	EXPECT_EQ(true, (v1 - v2) == v3);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	const size_t size1 = 5, size2 = 10;
	TDynamicVector<int> v1(size1), v2(size2);
	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	const size_t size = 3;
	int v3=0;
	TDynamicVector<int> v1(size), v2(size);
	for (size_t i = 0; i < size; i++)
	{
		v1[i] = 2;
		v2[i] = 5;
		v3 = (v1[i] * v2[i]) + v3;
	}
	EXPECT_EQ(true, (v1 * v2) == v3);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	//const size_t size1 = 5, size2 = 10;
	TDynamicVector<int> v1(5), v2(27);
	ASSERT_ANY_THROW(v1 * v2);
}

