﻿#if defined( DEBUG ) || defined( _DEBUG )
	#include "vld/include/vld.h"
#endif

#include "r2cm/r2cm_WindowUtility.h"
#include "psm/psm_VersionInfo.h"

#define DEVELOPMENT_PTT 1

#if defined( DEVELOPMENT_PTT ) && ( DEVELOPMENT_PTT == 1 )

	#include "r2cm/r2cm_Director.h"
	#include "DevelopmentMenu.h"

#else

	#include "r2bix/r2base_Director.h"
	#include "psm/psm_DirectorConfig.h"
	#include "psm/psm_scene_EntryScene.h"

#endif

int main()
{
	//
	// Environment : Title
	//
	r2cm::WindowUtility::ChangeTitle( psm::VersionInfo.String4Version );

#if defined( DEVELOPMENT_PTT ) && ( DEVELOPMENT_PTT == 1 )

	//
	// Environment : Size
	//
	r2cm::WindowUtility::Resize( 960, 960 );

	//
	// Environment : Position
	//
	r2cm::WindowUtility::Move( 0, 0 );

	//
	// Setup & Run
	//
	r2cm::Director director;
	director.Setup( DevelopmentMenu() );
	director.Run();

#else

	//
	// Environment : Size
	//
	r2cm::WindowUtility::Resize( 548, 548 );

	//
	// Environment : Position
	//
	r2cm::WindowUtility::Move( 0, 0 );

	//
	// Setup
	//
	r2base::Director director( psm::DirectorConfig );
	director.Setup( psm_scene::EntryScene::Create( director ) );

	//
	// Environment : ScrollBar | Maximize Button | Frame Lock
	//
	r2cm::WindowUtility::ScrollBarVisible( false );
	r2cm::WindowUtility::MaximizeButtonEnable( false );
	r2cm::WindowUtility::ResizingByDraggingEnable( false );
	r2cm::WindowUtility::QuickEditEnable( false );

	//
	// Run
	//
	director.Run();

#endif

	return 0;
}
