/**
 * Unit Tests for GoalUndo class
**/

#include <gtest/gtest.h>
#include "GoalUndo.h"

 using namespace std;
 
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

TEST(GoalUndoTest, undogoalemptyCheck)
{
	GoalUndo goalundo;
	goalundo.undoGoal();
	string tocheck ="";
	ASSERT_EQ(tocheck, goalundo.getGoal());
}

TEST (GoalUndoTest, UndoGoalTestCheck)
{
	GoalUndo goalundo;
	string tocheck = "Test Check";
	string emptycheck = "";
	goalundo.addOperation(tocheck);
	goalundo.undoGoal();
	ASSERT_EQ(emptycheck, goalundo.getGoal());
}

TEST (GoalUndoTest, emptyCheckUndoOperationsingle)
{
	GoalUndo goalundo;
	goalundo.undoGoal();
	string emptycheck = "";
	ASSERT_EQ(emptycheck, goalundo.getGoal());
}


TEST (GoalUndoTest, singleoperationUndooperation)
{
	GoalUndo goalundo;
	string tocheck = "Test 1";
	string emptycheck = "";
	goalundo.addOperation(tocheck);
	goalundo.undoOperation();
	ASSERT_EQ(emptycheck, goalundo.getGoal());
}

TEST(GoalUndoTest, multipleOperationUndooperation)
{
	GoalUndo goalundo;
	string tocheck = "Test 1";
	string tocheck1 = "Test 2";
	goalundo.addOperation(tocheck);
	goalundo.addOperation(tocheck1);
	goalundo.undoOperation();
	ASSERT_EQ(tocheck, goalundo.getGoal());
}


TEST (GoalUndoTest, emptyCheckUndoOperations)
{
	GoalUndo goalundo;
	string emptyCheck = "";
	string tocheck = " Test Check";
	goalundo.undoOperation(tocheck);
	ASSERT_EQ(emptyCheck, goalundo.getGoal());
}


TEST (GoalUndoTest, SingleOperationOneArgumentUndoOperation)
{
	GoalUndo goalundo;
	string tocheck = "Test check";
	string emptyCheck = "";
	goalundo.addOperation(tocheck);
	goalundo.undoOperation(tocheck);
	ASSERT_EQ(emptyCheck, goalundo.getOperations());
}

TEST (GoalUndoTest, MultipleOperationOneArgumentSameUndoOperation)
{
	GoalUndo goalundo;
	string tocheck = "Test check";
	string tocheck1 = "Test check 1";
	goalundo.addOperation(tocheck);
	goalundo.addOperation(tocheck1);
	goalundo.undoOperation(tocheck);
	ASSERT_EQ(tocheck1, goalundo.getOperations());
}

TEST (GoalUndoTest, MultipleOperationOneArgumentSameUndoOperationCheck)
{
	GoalUndo goalundo;
	string tocheck = "Test check";
	string tocheck1 = "Test check 1";
	string tocheck2 = "Random";
	string tocheckresult = "Test check Test check 1";
	goalundo.addOperation(tocheck);
	goalundo.addOperation(tocheck1);
	goalundo.undoOperation(tocheck2);
	ASSERT_EQ(tocheckresult, goalundo.getOperations());
}



TEST (GoalUndoTest, emptyGetGoalCheck)
{
  GoalUndo goalundo;
  string emptycheck = "";
  ASSERT_EQ (emptycheck, goalundo.getGoal());
}

TEST (GoalUndoTest, GetGoalCheck)
{
	GoalUndo goalundo;
	string tocheck = "";
	ASSERT_EQ(tocheck,goalundo.getGoal());
}

TEST (GoalUndoTest, EmptyCheckGetOperations)
{
	GoalUndo goalundo;
	string emptycheck = "";
	ASSERT_EQ (emptycheck,goalundo.getOperations());
}


TEST (GoalUndoTest, CheckGetOperations)
{
	GoalUndo goalundo;
	string tocheck = " TEST Check";
	goalundo.addOperation(tocheck);
	ASSERT_EQ(tocheck, goalundo.getOperations());
}

TEST (GoalUndoTest, MultipleOperationsUsingUndoOperations)
{
	GoalUndo goalundo;
	string tocheck = " TEST Check";
	string tocheck1 = "TEST Check 1";
	string tocheck2 = tocheck + " " + tocheck1;
	goalundo.addOperation(tocheck);
	goalundo.addOperation(tocheck1);
	ASSERT_EQ (tocheck2, goalundo.getOperations());
}

TEST (GoalUndoTest, EmptyTwoArgumentsCheckAddOperations)
{
	GoalUndo goalundo; 
	string tocheck = "";
	goalundo.addOperation(tocheck);
	ASSERT_EQ(tocheck, goalundo.getGoal());
}

TEST (GoalUndoTest, TwoArguementsCheckAddOperations)
{
	GoalUndo goalundo;
	string tocheck = "Test Check";
	string emptycheck = "";
	goalundo.addOperation(tocheck,emptycheck);
	ASSERT_EQ(emptycheck,goalundo.getGoal());
}

TEST (GoalUndoTest,swapTwoArgumentsCheckAddOperations)
{
	GoalUndo goalundo;
	string tocheck= "Test check";
	string emptycheck = "";
	goalundo.addOperation(emptycheck, tocheck);
	ASSERT_EQ(emptycheck, goalundo.getGoal());
}

TEST (GoalUndoTest, TwoArguementsCheckAddOperationsNotEmpty)
{
	GoalUndo goalundo;
	string tocheck= "Test check";
	string tocheck1 = "Test Check 1";
	goalundo.addOperation(tocheck, tocheck1 );
	ASSERT_EQ (tocheck, goalundo.getGoal());
}

TEST (GoalUndoTest, OneArguementNotEmptyCheckAddOperations)
{
	GoalUndo goalundo;
	string tocheck = "Test check";
	goalundo.addOperation(tocheck);
	ASSERT_EQ( tocheck, goalundo.getGoal());
}

TEST (GoalUndoTest, OneArguementNotEmptyCheckAddOperationsCheck)
{
	GoalUndo goalundo;
	string tocheck = "Test check";
	string tocheck1 = "Test check 1";
	goalundo.addOperation(tocheck);
	goalundo.addOperation(tocheck1);
	ASSERT_EQ (tocheck, goalundo.getGoal() );
	//ASSERT_EQ( tocheck, goalundo.getGoal());
}

TEST (GoalUndoTest, OneArguementEmptyCheckAddOperations)
{
	GoalUndo goalundo;
	string tocheck = "";
	goalundo.addOperation(tocheck);
	ASSERT_EQ (tocheck, goalundo.getGoal());
}