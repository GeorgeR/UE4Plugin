﻿////////////////////////////////////////////////////////////////////////////////////////////////////
// NoesisGUI - http://www.noesisengine.com
// Copyright (c) 2013 Noesis Technologies S.L. All Rights Reserved.
////////////////////////////////////////////////////////////////////////////////////////////////////

using UnrealBuildTool;
using System;
using System.IO;

public class Noesis : ModuleRules
{
	public Noesis(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		string NoesisBasePath = ModuleDirectory + "/NoesisSDK/";
		string NoesisIncludePath = NoesisBasePath + "Include/";

		PublicIncludePaths.Add(NoesisIncludePath);

		// Let's try to make sure the right version of the SDK is in the right place.
		const string RequiredRevision = "(r6972)";
		const string RequiredVersionName = "2.1.0f1";
		if (!Directory.Exists(NoesisBasePath))
		{
			throw new BuildException("Could not find NoesisGUI SDK in " + NoesisBasePath + ". Minimum required version is " + RequiredVersionName);
		}

		if (!Directory.Exists(NoesisBasePath + "Bin"))
		{
			throw new BuildException("Could not find NoesisGUI SDK Bin directory in " + NoesisBasePath + "Bin. Minimum required version is " + RequiredVersionName);
		}

		if (!Directory.Exists(NoesisBasePath + "Include"))
		{
			throw new BuildException("Could not find NoesisGUI SDK Include directory in " + NoesisBasePath + "Include. Minimum required version is " + RequiredVersionName);
		}

		if (!Directory.Exists(NoesisBasePath + "Lib"))
		{
			throw new BuildException("Could not find NoesisGUI SDK Lib directory in " + NoesisBasePath + "Lib. Minimum required version is " + RequiredVersionName);
		}

		string NoesisSdkVersionInfo;
		try
		{
			NoesisSdkVersionInfo = File.ReadAllText(NoesisBasePath + "version.txt");
		}
		catch (Exception)
		{
			throw new BuildException("Could not find NoesisGUI SDK version.txt in " + NoesisBasePath + "version.txt. Minimum required version is " + RequiredVersionName);
		}

		string[] SplitVersion = NoesisSdkVersionInfo.Split(' ');
		if (String.Compare(SplitVersion[SplitVersion.Length - 1], RequiredRevision) < 0)
		{
			throw new BuildException("Wrong version of the NoesisGUI SDK installed in " + NoesisBasePath + ". Minimum required version is " + RequiredVersionName);
		}

		PublicSystemIncludePaths.Add(NoesisIncludePath);

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			string NoesisLibPath = NoesisBasePath + "Lib/windows_x86_64/";
			PublicLibraryPaths.Add(NoesisLibPath);
			PublicAdditionalLibraries.Add("Noesis.lib");

			string NoesisDllPath = "/NoesisSDK/Bin/windows_x86_64/Noesis.dll";
			RuntimeDependencies.Add(ModuleDirectory + NoesisDllPath);

			PublicDefinitions.Add("NOESISGUI_DLL_PATH=\"NoesisGUI/Source/Noesis/" + NoesisDllPath + "\"");

			PublicDelayLoadDLLs.Add("Noesis.dll");
		}
		else if (Target.Platform == UnrealTargetPlatform.Mac)
		{
			string NoesisLibPath = NoesisBasePath + "Bin/osx/";
			PublicLibraryPaths.Add(NoesisLibPath);
			PublicAdditionalLibraries.Add(NoesisLibPath + "Noesis.dylib");

			string NoesisDylibPath = "/NoesisSDK/Bin/osx/Noesis.dylib";
			RuntimeDependencies.Add(ModuleDirectory + NoesisDylibPath);
		}
		else if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			string NoesisLibPath = NoesisBasePath + "Lib/ios/";
			PublicLibraryPaths.Add(NoesisLibPath);
			PublicAdditionalLibraries.Add("Noesis");

			PublicAdditionalShadowFiles.Add(Path.Combine(NoesisLibPath, "libNoesis.a"));
		}
		else if (Target.Platform == UnrealTargetPlatform.Android)
		{
			string NoesisLibPath = NoesisBasePath + "Bin/android_arm/";
			PublicLibraryPaths.Add(NoesisLibPath);
			PublicAdditionalLibraries.Add("Noesis");

			string NoesisAplPath = "/Noesis_APL.xml";
			AdditionalPropertiesForReceipt.Add("AndroidPlugin", ModuleDirectory + NoesisAplPath);
		}
		else if (Target.Platform == UnrealTargetPlatform.PS4)
		{
			string NoesisLibPath = NoesisBasePath + "Lib/ps4/";
			PublicAdditionalLibraries.Add(NoesisLibPath + "Noesis.a");
		}
	}
}
