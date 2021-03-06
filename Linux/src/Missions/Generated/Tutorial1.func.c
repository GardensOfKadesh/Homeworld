//
//  Tutorial1.func.c
//
//  Finite state machine function pointers for "Tutorial1" mission
//
//  This code was autogenerated from Tutorial1.kp by KAS2C Version 2.05sdl
//


#include "Tutorial1.h"  // prototypes and #includes for exposed game functions

// FSM init/watch function pointers.
const void* Tutorial1_FunctionPointers[] =
{
	(void*)Init_Tutorial1_Tutorial10,
	(void*)Watch_Tutorial1_Tutorial10,
	(void*)Init_Tutorial1_Tutorial10_IntroStart,
	(void*)Watch_Tutorial1_Tutorial10_IntroStart,
	(void*)Init_Tutorial1_Tutorial10_CameraStart,
	(void*)Watch_Tutorial1_Tutorial10_CameraStart,
	(void*)Init_Tutorial1_Tutorial10_CameraIntro,
	(void*)Watch_Tutorial1_Tutorial10_CameraIntro,
	(void*)Init_Tutorial1_Tutorial10_CameraMoveDescription,
	(void*)Watch_Tutorial1_Tutorial10_CameraMoveDescription,
	(void*)Init_Tutorial1_Tutorial10_CameraMove,
	(void*)Watch_Tutorial1_Tutorial10_CameraMove,
	(void*)Init_Tutorial1_Tutorial10_CameraMoveUp,
	(void*)Watch_Tutorial1_Tutorial10_CameraMoveUp,
	(void*)Init_Tutorial1_Tutorial10_CameraMoveDown,
	(void*)Watch_Tutorial1_Tutorial10_CameraMoveDown,
	(void*)Init_Tutorial1_Tutorial10_CameraBackToMiddle,
	(void*)Watch_Tutorial1_Tutorial10_CameraBackToMiddle,
	(void*)Init_Tutorial1_Tutorial10_CameraZoomDescription,
	(void*)Watch_Tutorial1_Tutorial10_CameraZoomDescription,
	(void*)Init_Tutorial1_Tutorial10_CameraZoomOut,
	(void*)Watch_Tutorial1_Tutorial10_CameraZoomOut,
	(void*)Init_Tutorial1_Tutorial10_CameraZoomIn,
	(void*)Watch_Tutorial1_Tutorial10_CameraZoomIn,
	(void*)Init_Tutorial1_Tutorial10_CameraPractice,
	(void*)Watch_Tutorial1_Tutorial10_CameraPractice,
	(void*)Init_Tutorial1_Tutorial10_TaskbarStart,
	(void*)Watch_Tutorial1_Tutorial10_TaskbarStart,
	(void*)Init_Tutorial1_Tutorial10_LessonTitleBuild,
	(void*)Watch_Tutorial1_Tutorial10_LessonTitleBuild,
	(void*)Init_Tutorial1_Tutorial10_TaskbarIntro,
	(void*)Watch_Tutorial1_Tutorial10_TaskbarIntro,
	(void*)Init_Tutorial1_Tutorial10_TaskbarDescription,
	(void*)Watch_Tutorial1_Tutorial10_TaskbarDescription,
	(void*)Init_Tutorial1_Tutorial10_BuildManagerStart,
	(void*)Watch_Tutorial1_Tutorial10_BuildManagerStart,
	(void*)Init_Tutorial1_Tutorial10_TaskbarBuildManagerButton,
	(void*)Watch_Tutorial1_Tutorial10_TaskbarBuildManagerButton,
	(void*)Init_Tutorial1_Tutorial10_BuildManagerIntro,
	(void*)Watch_Tutorial1_Tutorial10_BuildManagerIntro,
	(void*)Init_Tutorial1_Tutorial10_BuildManagerRUCount,
	(void*)Watch_Tutorial1_Tutorial10_BuildManagerRUCount,
	(void*)Init_Tutorial1_Tutorial10_BuildManagerShipList,
	(void*)Watch_Tutorial1_Tutorial10_BuildManagerShipList,
	(void*)Init_Tutorial1_Tutorial10_BuildManagerAddResCollector,
	(void*)Watch_Tutorial1_Tutorial10_BuildManagerAddResCollector,
	(void*)Init_Tutorial1_Tutorial10_BuildManagerIncrease,
	(void*)Watch_Tutorial1_Tutorial10_BuildManagerIncrease,
	(void*)Init_Tutorial1_Tutorial10_BuildManagerBuildRC,
	(void*)Watch_Tutorial1_Tutorial10_BuildManagerBuildRC,
	(void*)Init_Tutorial1_Tutorial10_BuildManagerIDProgressBar,
	(void*)Watch_Tutorial1_Tutorial10_BuildManagerIDProgressBar,
	(void*)Init_Tutorial1_Tutorial10_BuildManagerBuildResearchShip,
	(void*)Watch_Tutorial1_Tutorial10_BuildManagerBuildResearchShip,
	(void*)Init_Tutorial1_Tutorial10_BuildManagerHitBuildRS,
	(void*)Watch_Tutorial1_Tutorial10_BuildManagerHitBuildRS,
	(void*)Init_Tutorial1_Tutorial10_BuildManagerBuildScouts,
	(void*)Watch_Tutorial1_Tutorial10_BuildManagerBuildScouts,
	(void*)Init_Tutorial1_Tutorial10_BuildManagerHitBuildScouts,
	(void*)Watch_Tutorial1_Tutorial10_BuildManagerHitBuildScouts,
	(void*)Init_Tutorial1_Tutorial10_BuildManagerProgressBars,
	(void*)Watch_Tutorial1_Tutorial10_BuildManagerProgressBars,
	(void*)Init_Tutorial1_Tutorial10_BuildManagerBottomProgressBar,
	(void*)Watch_Tutorial1_Tutorial10_BuildManagerBottomProgressBar,
	(void*)Init_Tutorial1_Tutorial10_BuildManagerClose,
	(void*)Watch_Tutorial1_Tutorial10_BuildManagerClose,
	(void*)Init_Tutorial1_Tutorial10_SelectingStart,
	(void*)Watch_Tutorial1_Tutorial10_SelectingStart,
	(void*)Init_Tutorial1_Tutorial10_LessonTitleSelecting,
	(void*)Watch_Tutorial1_Tutorial10_LessonTitleSelecting,
	(void*)Init_Tutorial1_Tutorial10_SelectIntroZoomOut,
	(void*)Watch_Tutorial1_Tutorial10_SelectIntroZoomOut,
	(void*)Init_Tutorial1_Tutorial10_SelectIntro,
	(void*)Watch_Tutorial1_Tutorial10_SelectIntro,
	(void*)Init_Tutorial1_Tutorial10_DeselectMothership,
	(void*)Watch_Tutorial1_Tutorial10_DeselectMothership,
	(void*)Init_Tutorial1_Tutorial10_BandboxMothership,
	(void*)Watch_Tutorial1_Tutorial10_BandboxMothership,
	(void*)Init_Tutorial1_Tutorial10_SelectInfoOverlay,
	(void*)Watch_Tutorial1_Tutorial10_SelectInfoOverlay,
	(void*)Init_Tutorial1_Tutorial10_SelectBandboxAll,
	(void*)Watch_Tutorial1_Tutorial10_SelectBandboxAll,
	(void*)Init_Tutorial1_Tutorial10_SelectOverlayClick,
	(void*)Watch_Tutorial1_Tutorial10_SelectOverlayClick,
	(void*)Init_Tutorial1_Tutorial10_SelectResCollect,
	(void*)Watch_Tutorial1_Tutorial10_SelectResCollect,
	(void*)Init_Tutorial1_Tutorial10_FocusResCollect,
	(void*)Watch_Tutorial1_Tutorial10_FocusResCollect,
	(void*)Init_Tutorial1_Tutorial10_SelectMoveCamera,
	(void*)Watch_Tutorial1_Tutorial10_SelectMoveCamera,
	(void*)Init_Tutorial1_Tutorial10_CameraFocusAgain,
	(void*)Watch_Tutorial1_Tutorial10_CameraFocusAgain,
	(void*)Init_Tutorial1_Tutorial10_SelectFocusIn,
	(void*)Watch_Tutorial1_Tutorial10_SelectFocusIn,
	(void*)Init_Tutorial1_Tutorial10_SelectScouts,
	(void*)Watch_Tutorial1_Tutorial10_SelectScouts,
	(void*)Init_Tutorial1_Tutorial10_SelectFocusScouts,
	(void*)Watch_Tutorial1_Tutorial10_SelectFocusScouts,
	(void*)Init_Tutorial1_Tutorial10_ScoutsCenteredFocusIn,
	(void*)Watch_Tutorial1_Tutorial10_ScoutsCenteredFocusIn,
	(void*)Init_Tutorial1_Tutorial10_ScoutsCloseup,
	(void*)Watch_Tutorial1_Tutorial10_ScoutsCloseup,
	(void*)Init_Tutorial1_Tutorial10_SelectFocusPractice,
	(void*)Watch_Tutorial1_Tutorial10_SelectFocusPractice,
	(void*)Init_Tutorial1_Tutorial10_SelectResourceCollector,
	(void*)Watch_Tutorial1_Tutorial10_SelectResourceCollector,
	(void*)Init_Tutorial1_Tutorial10_SelectResCollHealthBar,
	(void*)Watch_Tutorial1_Tutorial10_SelectResCollHealthBar,
	(void*)Init_Tutorial1_Tutorial10_SelectResCollContextMenu,
	(void*)Watch_Tutorial1_Tutorial10_SelectResCollContextMenu,
	(void*)Init_Tutorial1_Tutorial10_SelectResCollDescribeContextMenu,
	(void*)Watch_Tutorial1_Tutorial10_SelectResCollDescribeContextMenu,
	(void*)Init_Tutorial1_Tutorial10_SelectResCollCollecting,
	(void*)Watch_Tutorial1_Tutorial10_SelectResCollCollecting,
	(void*)Init_Tutorial1_Tutorial10_SelectFocusResearchShip,
	(void*)Watch_Tutorial1_Tutorial10_SelectFocusResearchShip,
	(void*)Init_Tutorial1_Tutorial10_ResearchStart,
	(void*)Watch_Tutorial1_Tutorial10_ResearchStart,
	(void*)Init_Tutorial1_Tutorial10_LessonTitleResearch,
	(void*)Watch_Tutorial1_Tutorial10_LessonTitleResearch,
	(void*)Init_Tutorial1_Tutorial10_ResearchIntro,
	(void*)Watch_Tutorial1_Tutorial10_ResearchIntro,
	(void*)Init_Tutorial1_Tutorial10_TaskbarResearchManagerButton,
	(void*)Watch_Tutorial1_Tutorial10_TaskbarResearchManagerButton,
	(void*)Init_Tutorial1_Tutorial10_ResearchManagerScreen,
	(void*)Watch_Tutorial1_Tutorial10_ResearchManagerScreen,
	(void*)Init_Tutorial1_Tutorial10_ResearchManagerTopicWindow,
	(void*)Watch_Tutorial1_Tutorial10_ResearchManagerTopicWindow,
	(void*)Init_Tutorial1_Tutorial10_ResearchManagerGreenDot,
	(void*)Watch_Tutorial1_Tutorial10_ResearchManagerGreenDot,
	(void*)Init_Tutorial1_Tutorial10_ResearchManagerSelectTech,
	(void*)Watch_Tutorial1_Tutorial10_ResearchManagerSelectTech,
	(void*)Init_Tutorial1_Tutorial10_ResearchManagerTopicDescription,
	(void*)Watch_Tutorial1_Tutorial10_ResearchManagerTopicDescription,
	(void*)Init_Tutorial1_Tutorial10_ResearchManagerResearching,
	(void*)Watch_Tutorial1_Tutorial10_ResearchManagerResearching,
	(void*)Init_Tutorial1_Tutorial10_ResearchManagerClose,
	(void*)Watch_Tutorial1_Tutorial10_ResearchManagerClose,
	(void*)Init_Tutorial1_Tutorial10_MoveStart,
	(void*)Watch_Tutorial1_Tutorial10_MoveStart,
	(void*)Init_Tutorial1_Tutorial10_LessonTitleMove,
	(void*)Watch_Tutorial1_Tutorial10_LessonTitleMove,
	(void*)Init_Tutorial1_Tutorial10_MoveBuildRemainingScouts,
	(void*)Watch_Tutorial1_Tutorial10_MoveBuildRemainingScouts,
	(void*)Init_Tutorial1_Tutorial10_MoveSelectScouts,
	(void*)Watch_Tutorial1_Tutorial10_MoveSelectScouts,
	(void*)Init_Tutorial1_Tutorial10_MoveFocusScouts,
	(void*)Watch_Tutorial1_Tutorial10_MoveFocusScouts,
	(void*)Init_Tutorial1_Tutorial10_MoveCameraOverview,
	(void*)Watch_Tutorial1_Tutorial10_MoveCameraOverview,
	(void*)Init_Tutorial1_Tutorial10_MoveCameraZoomOut,
	(void*)Watch_Tutorial1_Tutorial10_MoveCameraZoomOut,
	(void*)Init_Tutorial1_Tutorial10_MoveContextMenu,
	(void*)Watch_Tutorial1_Tutorial10_MoveContextMenu,
	(void*)Init_Tutorial1_Tutorial10_MoveSelectMove,
	(void*)Watch_Tutorial1_Tutorial10_MoveSelectMove,
	(void*)Init_Tutorial1_Tutorial10_MovePizzaDishIntro,
	(void*)Watch_Tutorial1_Tutorial10_MovePizzaDishIntro,
	(void*)Init_Tutorial1_Tutorial10_MoveScoutsMove,
	(void*)Watch_Tutorial1_Tutorial10_MoveScoutsMove,
	(void*)Init_Tutorial1_Tutorial10_MoveHitM,
	(void*)Watch_Tutorial1_Tutorial10_MoveHitM,
	(void*)Init_Tutorial1_Tutorial10_MoveCameraPizzaDish,
	(void*)Watch_Tutorial1_Tutorial10_MoveCameraPizzaDish,
	(void*)Init_Tutorial1_Tutorial10_MoveHitM2,
	(void*)Watch_Tutorial1_Tutorial10_MoveHitM2,
	(void*)Init_Tutorial1_Tutorial10_MoveUp,
	(void*)Watch_Tutorial1_Tutorial10_MoveUp,
	(void*)Init_Tutorial1_Tutorial10_MoveUpRelease,
	(void*)Watch_Tutorial1_Tutorial10_MoveUpRelease,
	(void*)Init_Tutorial1_Tutorial10_MovePractice,
	(void*)Watch_Tutorial1_Tutorial10_MovePractice,
	(void*)Init_Tutorial1_Tutorial10_SMStart,
	(void*)Watch_Tutorial1_Tutorial10_SMStart,
	(void*)Init_Tutorial1_Tutorial10_LessonTitleSM,
	(void*)Watch_Tutorial1_Tutorial10_LessonTitleSM,
	(void*)Init_Tutorial1_Tutorial10_SMIntro,
	(void*)Watch_Tutorial1_Tutorial10_SMIntro,
	(void*)Init_Tutorial1_Tutorial10_SMPressSensors,
	(void*)Watch_Tutorial1_Tutorial10_SMPressSensors,
	(void*)Init_Tutorial1_Tutorial10_SMSensorsManager,
	(void*)Watch_Tutorial1_Tutorial10_SMSensorsManager,
	(void*)Init_Tutorial1_Tutorial10_SMDescriptionMoShip,
	(void*)Watch_Tutorial1_Tutorial10_SMDescriptionMoShip,
	(void*)Init_Tutorial1_Tutorial10_SMDescriptionGreenDot,
	(void*)Watch_Tutorial1_Tutorial10_SMDescriptionGreenDot,
	(void*)Init_Tutorial1_Tutorial10_SMDescriptionRedDot,
	(void*)Watch_Tutorial1_Tutorial10_SMDescriptionRedDot,
	(void*)Init_Tutorial1_Tutorial10_SMDescriptionLgBrownDot,
	(void*)Watch_Tutorial1_Tutorial10_SMDescriptionLgBrownDot,
	(void*)Init_Tutorial1_Tutorial10_SMDescriptionSmBrownDot,
	(void*)Watch_Tutorial1_Tutorial10_SMDescriptionSmBrownDot,
	(void*)Init_Tutorial1_Tutorial10_SMBandBox,
	(void*)Watch_Tutorial1_Tutorial10_SMBandBox,
	(void*)Init_Tutorial1_Tutorial10_SMExit,
	(void*)Watch_Tutorial1_Tutorial10_SMExit,
	(void*)Init_Tutorial1_Tutorial10_SMSelected,
	(void*)Watch_Tutorial1_Tutorial10_SMSelected,
	(void*)Init_Tutorial1_Tutorial10_SMMoveButton,
	(void*)Watch_Tutorial1_Tutorial10_SMMoveButton,
	(void*)Init_Tutorial1_Tutorial10_SMFocus,
	(void*)Watch_Tutorial1_Tutorial10_SMFocus,
	(void*)Init_Tutorial1_Tutorial10_SMPractice,
	(void*)Watch_Tutorial1_Tutorial10_SMPractice,
	(void*)Init_Tutorial1_Tutorial10_FormationStart,
	(void*)Watch_Tutorial1_Tutorial10_FormationStart,
	(void*)Init_Tutorial1_Tutorial10_LessonTitleFormations,
	(void*)Watch_Tutorial1_Tutorial10_LessonTitleFormations,
	(void*)Init_Tutorial1_Tutorial10_FormationIntro,
	(void*)Watch_Tutorial1_Tutorial10_FormationIntro,
	(void*)Init_Tutorial1_Tutorial10_FormationDelta,
	(void*)Watch_Tutorial1_Tutorial10_FormationDelta,
	(void*)Init_Tutorial1_Tutorial10_FormationDeltaBroad,
	(void*)Watch_Tutorial1_Tutorial10_FormationDeltaBroad,
	(void*)Init_Tutorial1_Tutorial10_FormationBroadX,
	(void*)Watch_Tutorial1_Tutorial10_FormationBroadX,
	(void*)Init_Tutorial1_Tutorial10_FormationXClaw,
	(void*)Watch_Tutorial1_Tutorial10_FormationXClaw,
	(void*)Init_Tutorial1_Tutorial10_FormationClawWall,
	(void*)Watch_Tutorial1_Tutorial10_FormationClawWall,
	(void*)Init_Tutorial1_Tutorial10_FormationWallSphere,
	(void*)Watch_Tutorial1_Tutorial10_FormationWallSphere,
	(void*)Init_Tutorial1_Tutorial10_FormationPractice,
	(void*)Watch_Tutorial1_Tutorial10_FormationPractice,
	(void*)Init_Tutorial1_Tutorial10_LookForEnemy,
	(void*)Watch_Tutorial1_Tutorial10_LookForEnemy,
	(void*)Init_Tutorial1_Tutorial10_LookInSensors,
	(void*)Watch_Tutorial1_Tutorial10_LookInSensors,
	(void*)Init_Tutorial1_Tutorial10_LeaveSensors,
	(void*)Watch_Tutorial1_Tutorial10_LeaveSensors,
	(void*)Init_Tutorial1_Tutorial10_AttackingStart,
	(void*)Watch_Tutorial1_Tutorial10_AttackingStart,
	(void*)Init_Tutorial1_Tutorial10_LessonTitleAttacking,
	(void*)Watch_Tutorial1_Tutorial10_LessonTitleAttacking,
	(void*)Init_Tutorial1_Tutorial10_AttackingMouseOver,
	(void*)Watch_Tutorial1_Tutorial10_AttackingMouseOver,
	(void*)Init_Tutorial1_Tutorial10_BandboxAttack,
	(void*)Watch_Tutorial1_Tutorial10_BandboxAttack,
	(void*)Init_Tutorial1_Tutorial10_AttackingTimeStop,
	(void*)Watch_Tutorial1_Tutorial10_AttackingTimeStop,
	(void*)Init_Tutorial1_Tutorial10_AltFocusStart,
	(void*)Watch_Tutorial1_Tutorial10_AltFocusStart,
	(void*)Init_Tutorial1_Tutorial10_LessonTitleAltFocus,
	(void*)Watch_Tutorial1_Tutorial10_LessonTitleAltFocus,
	(void*)Init_Tutorial1_Tutorial10_AltFocus,
	(void*)Watch_Tutorial1_Tutorial10_AltFocus,
	(void*)Init_Tutorial1_Tutorial10_AltFocusBandbox,
	(void*)Watch_Tutorial1_Tutorial10_AltFocusBandbox,
	(void*)Init_Tutorial1_Tutorial10_PracticeAndUnPause,
	(void*)Watch_Tutorial1_Tutorial10_PracticeAndUnPause,
	(void*)Init_Tutorial1_Tutorial10_BuildFrigate,
	(void*)Watch_Tutorial1_Tutorial10_BuildFrigate,
	(void*)Init_Tutorial1_Tutorial10_BuildFrigateStart,
	(void*)Watch_Tutorial1_Tutorial10_BuildFrigateStart,
	(void*)Init_Tutorial1_Tutorial10_BuildFrigateUnderway,
	(void*)Watch_Tutorial1_Tutorial10_BuildFrigateUnderway,
	(void*)Init_Tutorial1_Tutorial10_DockStart,
	(void*)Watch_Tutorial1_Tutorial10_DockStart,
	(void*)Init_Tutorial1_Tutorial10_LessonTitleDock,
	(void*)Watch_Tutorial1_Tutorial10_LessonTitleDock,
	(void*)Init_Tutorial1_Tutorial10_Docking,
	(void*)Watch_Tutorial1_Tutorial10_Docking,
	(void*)Init_Tutorial1_Tutorial10_SelectDock,
	(void*)Watch_Tutorial1_Tutorial10_SelectDock,
	(void*)Init_Tutorial1_Tutorial10_ScoutsDocking,
	(void*)Watch_Tutorial1_Tutorial10_ScoutsDocking,
	(void*)Init_Tutorial1_Tutorial10_CancelCommandStart,
	(void*)Watch_Tutorial1_Tutorial10_CancelCommandStart,
	(void*)Init_Tutorial1_Tutorial10_LessonTitleCancelCommand,
	(void*)Watch_Tutorial1_Tutorial10_LessonTitleCancelCommand,
	(void*)Init_Tutorial1_Tutorial10_CancelCommandIntro,
	(void*)Watch_Tutorial1_Tutorial10_CancelCommandIntro,
	(void*)Init_Tutorial1_Tutorial10_CancelCommandContextMenu,
	(void*)Watch_Tutorial1_Tutorial10_CancelCommandContextMenu,
	(void*)Init_Tutorial1_Tutorial10_CancelCommand,
	(void*)Watch_Tutorial1_Tutorial10_CancelCommand,
	(void*)Init_Tutorial1_Tutorial10_CancelCommandDescription,
	(void*)Watch_Tutorial1_Tutorial10_CancelCommandDescription,
	(void*)Init_Tutorial1_Tutorial10_PracticeStart,
	(void*)Watch_Tutorial1_Tutorial10_PracticeStart,
	(void*)Init_Tutorial1_Tutorial10_TutorialPractice,
	(void*)Watch_Tutorial1_Tutorial10_TutorialPractice,
	(void*)Init_Tutorial1_Tutorial10_TutorialFinish,
	(void*)Watch_Tutorial1_Tutorial10_TutorialFinish,
	(void*)Init_Tutorial1_Tutorial10_Main,
	(void*)Watch_Tutorial1_Tutorial10_Main,
	(void*)Init_Tutorial1_HideUnhide,
	(void*)Watch_Tutorial1_HideUnhide,
	(void*)Init_Tutorial1_HideUnhide_Hidden,
	(void*)Watch_Tutorial1_HideUnhide_Hidden,
	(void*)Init_Tutorial1_HideUnhide_SitAroundAndTakeIt,
	(void*)Watch_Tutorial1_HideUnhide_SitAroundAndTakeIt,
	(void*)Init_Tutorial1_HideUnhide_Idle,
	(void*)Watch_Tutorial1_HideUnhide_Idle,
	(void*)Init_Tutorial1_HideUnhide_AttackEnemy,
	(void*)Watch_Tutorial1_HideUnhide_AttackEnemy,
	(void*)Init_Tutorial1_HideUnhide_WaitForMore,
	(void*)Watch_Tutorial1_HideUnhide_WaitForMore,
	(void*)Init_Tutorial1_HideUnhide_NullState,
	(void*)Watch_Tutorial1_HideUnhide_NullState,
	(void*)Init_Tutorial1,
	(void*)Watch_Tutorial1,
};

// Number of FSM init/watch function pointers.
const unsigned int Tutorial1_FunctionPointerCount = 302;
