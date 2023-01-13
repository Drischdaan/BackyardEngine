<a name="readme-top"></a>

<div align="center">
  <a href="https://github.com/Drischdaan/BackyardEngine">
    <img src="https://raw.githubusercontent.com/Backyard-Studios/Branding/24006b7753330c3193ae399bb792a810304aea37/Logo/Logo.svg" alt="Logo" width="320" height="120">
  </a>
  <h3 align="center">Backyard Engine</h3>
  <p align="center">
    An educational game engine for me to learn graphics programming
    <br/>
    <a href="https://trello.com/b/Ro0Y7eFF/backyard-engine"><strong>Explore the roadmap »</strong></a>
    <br />
  </p>
</div>

<div align="center">

  [![Issues][issues-shield]][issues-url]
  [![MIT License][license-shield]][license-url]

</div>

## 🪵 Branches

| Branch                               | Description                                                   |
|--------------------------------------|---------------------------------------------------------------|
| `main`                               | Contains the latest stable version.                           |
| `develop`<sup>(default branch)</sup> | Contains the latest development version. Most likely unstable |
| `feature/*`                          | Contains a feature that is currently being developed.         |
| `fix/*`                              | Contains a fix that is currently being developed.             |

## 🛠️ Roadmap *(WIP)*

You can find a detailed roadmap and the progress on the the [trello board][trello-board].

**Supported rendering apis:**

- [ ] Vulkan
- [ ] DirectX 11
- [ ] *(Considering) DirectX 12*

> **ℹ️ Info:** I made the decision to not implement OpenGL for now. Also, because of a lack of hardware, I am not adding macOS support in the near future

## 🪛 Structure

<img src="https://i.imgur.com/pUdK0I1.jpg">

## 🚀 Development

### Requirements

You have to install following dependencies before setting up the development environment:

- [Vulkan SDK (1.3.236.0)](https://sdk.lunarg.com/sdk/download/1.3.236.0/windows/VulkanSDK-1.3.236.0-Installer.exe)

### Setup

In order to setup a working development environment you first have to clone the library with all its submodules.

```shell
$ git clone --recursive https://github.com/Drischdaan/BackyardEngine
```

After you cloned the repository you have to generate the project files with the correct script for your right operating system.

```shell
# Windows
$ .\Tools\Scripts\GenerateProjectFiles.bat
```

> **❗Note:** Execute the command in the root of the repository

## 📜 License

Distributed under the MIT License. See `LICENSE` for more information.

## 🫱🏽‍🫲🏽 Contact

[![Github][Github]][Github-url]
[![Discord][Discord]][Discord-url]
[![Twitter][Twitter]][Twitter-url]

<div>
    <a href="https://www.buymeacoffee.com/Drischdaan">
        <img src="https://img.buymeacoffee.com/button-api/?text=Buy me a coffee&emoji=&slug=Drischdaan&button_colour=BD5FFF&font_colour=ffffff&font_family=Lato&outline_colour=000000&coffee_colour=FFDD00">
    </a>
</div>

<!-- Variables -->
[issues-shield]: https://img.shields.io/github/issues/Drischdaan/BackyardEngine.svg?style=for-the-badge
[issues-url]: https://github.com/Drischdaan/BackyardEngine/issues
[license-shield]: https://img.shields.io/github/license/Drischdaan/BackyardEngine.svg?style=for-the-badge
[license-url]: https://github.com/Drischdaan/BackyardEngine/blob/master/LICENSE.txt
[trello-board]: https://trello.com/b/Ro0Y7eFF/backyard-engine

<!-- Socials -->
[Github]: https://skillicons.dev/icons?i=github
[Github-url]: https://github.com/Drischdaan
[Discord]: https://skillicons.dev/icons?i=discord
[Discord-url]: https://discord.com/users/244115221776433152
[Twitter]: https://skillicons.dev/icons?i=twitter
[Twitter-url]: https://twitter.com/Drischdaan

<!-- https://github.com/tandpfun/skill-icons -->
<!-- https://github.com/Ileriayo/markdown-badges -->