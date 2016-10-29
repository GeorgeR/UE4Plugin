////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiBaseGridViewRowPresenter.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiBaseGridViewRowPresenter::UNoesisGuiBaseGridViewRowPresenter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiBaseGridViewRowPresenter::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::BaseGridViewRowPresenter* NoesisBaseGridViewRowPresenter = NsDynamicCast<Noesis::Gui::BaseGridViewRowPresenter*>(InNoesisComponent);
	check(NoesisBaseGridViewRowPresenter);
}

void UNoesisGuiBaseGridViewRowPresenter::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::BaseGridViewRowPresenter* NoesisBaseGridViewRowPresenter = NsDynamicCast<Noesis::Gui::BaseGridViewRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisBaseGridViewRowPresenter)


}

void UNoesisGuiBaseGridViewRowPresenter::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::BaseGridViewRowPresenter* NoesisBaseGridViewRowPresenter = NsDynamicCast<Noesis::Gui::BaseGridViewRowPresenter*>(NoesisComponent.GetPtr());
	check(NoesisBaseGridViewRowPresenter)


}

