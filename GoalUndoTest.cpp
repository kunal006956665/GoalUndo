/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"
 
class GoalUndoTest : public ::testing::Test
{
	protected:
		GoalUndoTest(){}
		virtual ~GoalUndoTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(GoalUndoTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(GoalUndoTest, EmptyGetGoalCheck)
{
        GoalUndo obj;
	ASSERT_EQ("", obj.getGoal());
}

TEST(GoalUndoTest, Empty_AddOP_1ARG_Check)
{
        GoalUndo obj;
        obj.addOperation("");
	obj.undoGoal();
	obj.undoOperation();
	obj.undoOperation("a");
	ASSERT_EQ("", obj.getGoal());
	ASSERT_EQ("", obj.getOperations());
}

TEST(GoalUndoTest, First_AddOP_1ARG_Check)
{
        GoalUndo obj;
        obj.addOperation("OP1");
        ASSERT_EQ("OP1", obj.getGoal());
        ASSERT_EQ("OP1", obj.getOperations());
	obj.undoGoal();
	ASSERT_EQ("", obj.getGoal());
        ASSERT_EQ("", obj.getOperations());
}

TEST(GoalUndoTest, ADDtoAddedGoal__AddOP_1ARG_Check)
{
        GoalUndo obj;
        obj.addOperation("OP1");
        ASSERT_EQ("OP1", obj.getGoal());
        ASSERT_EQ("OP1", obj.getOperations());
	obj.addOperation("OP2");
	ASSERT_EQ("OP1", obj.getGoal());
        ASSERT_EQ("OP1 OP2", obj.getOperations());
	obj.undoOperation("OP33");
	ASSERT_EQ("OP1", obj.getGoal());
        ASSERT_EQ("OP1 OP2", obj.getOperations());
	obj.undoOperation();
	ASSERT_EQ("OP1", obj.getGoal());
        ASSERT_EQ("OP1", obj.getOperations());
	obj.undoOperation("OP1");
	ASSERT_EQ("OP1", obj.getGoal());
        ASSERT_EQ("", obj.getOperations());
}

TEST(GoalUndoTest, undoOP_Check)
{
        GoalUndo obj;
        obj.addOperation("OP1");
        ASSERT_EQ("OP1", obj.getGoal());
        ASSERT_EQ("OP1", obj.getOperations());
        obj.addOperation("OP2");
        ASSERT_EQ("OP1", obj.getGoal());
        ASSERT_EQ("OP1 OP2", obj.getOperations());
	obj.undoOperation();
        ASSERT_EQ("OP1", obj.getGoal());
        ASSERT_EQ("OP1", obj.getOperations());
	obj.undoOperation();
        ASSERT_EQ("", obj.getGoal());
        ASSERT_EQ("", obj.getOperations());
}


TEST(GoalUndoTest, Empty_AddOP_2ARG_Check)
{
        GoalUndo obj;
	obj.addOperation("","");
        ASSERT_EQ("", obj.getGoal());
}

TEST(GoalUndoTest, OneEmpty_AddOP_2ARG_Check)
{
        GoalUndo obj;
	obj.addOperation("CHECK1","");
        ASSERT_EQ("", obj.getGoal());
}

TEST(GoalUndoTest, SecondEmpty_AddOP_2ARG_Check)
{
        GoalUndo obj;
	obj.addOperation("","CHECK2");
	ASSERT_EQ("", obj.getGoal());
}

TEST(GoalUndoTest, Multiple_GetOperations_Check)
{
        GoalUndo obj;
        obj.addOperation("Goal1","OP1");
	obj.addOperation("OP2");
	obj.addOperation("OP3");
	obj.addOperation("OP4");
	obj.addOperation("OP5");
	ASSERT_EQ("OP1 OP2 OP3 OP4 OP5", obj.getOperations());
}

TEST(GoalUndoTest, Add_to_same_goal_Check)
{
        GoalUndo obj;
        obj.addOperation("Goal1","OP1");
	obj.addOperation("Goal1","OP2");
	ASSERT_EQ("Goal1", obj.getGoal());
	ASSERT_EQ("OP2", obj.getOperations());
}

