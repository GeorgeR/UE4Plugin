////////////////////////////////////////////////////////////////////////////////////////////////////
// Noesis Engine - http://www.noesisengine.com
// Copyright (c) 2009-2010 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "NoesisGuiPrivatePCH.h"
#include "GeneratedClasses/NoesisGuiItemsPanelTemplate.h"

using namespace Noesis;
using namespace Gui;

UNoesisGuiItemsPanelTemplate::UNoesisGuiItemsPanelTemplate(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UNoesisGuiItemsPanelTemplate::SetNoesisComponent(Noesis::Core::BaseComponent* InNoesisComponent)
{
	Super::SetNoesisComponent(InNoesisComponent);

	Noesis::Gui::ItemsPanelTemplate* NoesisItemsPanelTemplate = NsDynamicCast<Noesis::Gui::ItemsPanelTemplate*>(InNoesisComponent);
	check(NoesisItemsPanelTemplate);
}

void UNoesisGuiItemsPanelTemplate::BindEvents()
{
	Super::BindEvents();

	Noesis::Gui::ItemsPanelTemplate* NoesisItemsPanelTemplate = NsDynamicCast<Noesis::Gui::ItemsPanelTemplate*>(NoesisComponent.GetPtr());
	check(NoesisItemsPanelTemplate)


}

void UNoesisGuiItemsPanelTemplate::UnbindEvents()
{
	Super::UnbindEvents();

	Noesis::Gui::ItemsPanelTemplate* NoesisItemsPanelTemplate = NsDynamicCast<Noesis::Gui::ItemsPanelTemplate*>(NoesisComponent.GetPtr());
	check(NoesisItemsPanelTemplate)


}

