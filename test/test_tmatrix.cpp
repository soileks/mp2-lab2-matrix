#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> m1(10);
	TDynamicMatrix<int> m2(m1);
	EXPECT_EQ(true, m1 == m2);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m1(10);
	TDynamicMatrix<int> m2(m1);
	EXPECT_EQ(false, &m1 ==&m2);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> v(4);

	EXPECT_EQ(4, v.size());

}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(4);
	m[0][0] = 4;

	EXPECT_EQ(4, m[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(10);
	ASSERT_ANY_THROW(m.at(-3));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(10);
	ASSERT_ANY_THROW(m.at(11));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(5);
	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	const size_t size = 2;
	TDynamicMatrix<int> m1(size), m2(size);
	for (size_t i = 0; i < size; i++)
		for (size_t j = 0; j < size; j++)
		{
			m1[i][j] = 0;
			m2[i][j] = 1;
		}
	m2 = m1;
	for (size_t i = 0; i < size; i++)
		for (size_t j = 0; j < size; j++)
			EXPECT_NE(1, m2[i][j]);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	const size_t size1 = 2, size2 = 5;
	TDynamicMatrix<int> m1(size1), m2(size2);
	m2 = m1;
	EXPECT_EQ(size1, m2.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	const size_t size1 = 2, size2 = 5;
	TDynamicMatrix<int> m1(size1), m2(size2);
	for (size_t i = 0; i < size1; i++)
		for (size_t j = 0; j < size1; j++)
			m1[i][j] = 1;
	m2 = m1;
	for (size_t i = 0; i < size1; i++)
		for (size_t j = 0; j < size1; j++)
			EXPECT_NE(0, m2[i][j]);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	const size_t size = 2;
	TDynamicMatrix<int> m1(size), m2(size);
	for (size_t i = 0; i < size; i++)
		for (size_t j = 0; j < size; j++)
		{
			m1[i][j] = i + j;
			m2[i][j] = i + j;
		}
	EXPECT_EQ(true, m1 == m2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(10);
	EXPECT_EQ(true, m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m1(5), m2(10);
	EXPECT_EQ(false, m1 == m2);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	const size_t size = 5;
	TDynamicMatrix<int> m1(size), m2(size), m3(size);
	for (size_t i = 0; i < size; i++)
		for (size_t j = 0; j < size; j++)
		{
			m1[i][j] = 4;
			m2[i][j] = 5;
			m3[i][j] = m1[i][j] + m2[i][j];
		}
	EXPECT_EQ(true, (m1 + m2) == m3);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	const size_t size1 = 2, size2 = 4;
	TDynamicMatrix<int> m1(size1), m2(size2);
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	const size_t size = 5;
	TDynamicMatrix<int> m1(size), m2(size), m3(size);
	for (size_t i = 0; i < size; i++)
		for (size_t j = 0; j < size; j++)
		{
			m1[i][j] = 4;
			m2[i][j] = 5;
			m3[i][j] = m1[i][j] - m2[i][j];
		}
	EXPECT_EQ(true, (m1 - m2) == m3);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	const size_t size1 = 2, size2 = 4;
	TDynamicMatrix<int> m1(size1), m2(size2);
	ASSERT_ANY_THROW(m1 - m2);
}

